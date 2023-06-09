#include "utils/drawing.h"
#include "utils/time.h"
#include "utils/constants.h"
#include "core/card/treasure_card.h"
#include "core/card/relic_card.h"
#include <iostream>

void DrawTextCenter(std::string const& text, int fontSize, Color color)
{
    const int text_width = MeasureText(text.c_str(), fontSize);
    const int x = (GetScreenWidth() - text_width) / 2;
    const int y = GetScreenHeight() / 2;
    DrawText(text.c_str(), x, y, fontSize, color);
}

void DrawTextCenterX(std::string const& text, int y, int fontSize, Color color)
{
    const int text_width = MeasureText(text.c_str(), fontSize);
    const int x = (GetScreenWidth() - text_width) / 2;
    DrawText(text.c_str(), x, y, fontSize, color);
}

void DrawTimer(long time_ms, int fontSize, Color color)
{
    const std::string time = time_to_string(time_ms);
    const int text_width = MeasureText(time.c_str(), fontSize);
    const int x = (GetScreenWidth() - text_width) - 10;
    const int y = 10;
    DrawText(time.c_str(), x, y, fontSize, color);
}

void DrawRound(int current, int max, int fontSize, Color color)
{
    const std::string round = "Round " + std::to_string(current) + "/" + std::to_string(max);
    const int text_width = MeasureText(round.c_str(), fontSize);
    const int x = (GetScreenWidth() - text_width) / 2;
    const int y = 10;
    DrawText(round.c_str(), x, y, fontSize, color);
}

void DrawCards(diamant::deck& deck)
{
    const int max_cards_per_row = 5;
    const int panel_width = static_cast<int>(WINDOW_WIDTH * 0.7);     //max_cards_per_row * CARD_WIDTH + (max_cards_per_row - 1) * CARD_PADDING;
    int panelX = 220;                               //((WINDOW_WIDTH - panel_width) / 2) + 50;
    int panelY = 220;

    DrawRectangle(panelX-5, panelY-5, panel_width+10, PANEL_HEIGHT+5, Fade(WHITE, 0.7f));

    // Déclarer une variable statique pour stocker la position y de la panel
    static int panelYScroll = panelY;
    
    // Handle mouse wheel input to adjust panel position
    static int scrollY = 0;
    const int scrollSpeed = 40;
    int wheelMove = -GetMouseWheelMove(); // inverser le signe pour inverser le scroll
    if (wheelMove != 0) {
        panelYScroll -= wheelMove * scrollSpeed;
        if (panelYScroll < -400) {
            panelYScroll = -400;
        } else if (panelYScroll > 220) {
            panelYScroll = 220;
        }
    }

    static Texture2D backside = LoadTexture("../../assets/backside.png");
    static Vector2 position = { 50.f, static_cast<float>(panelY) };
    DrawTextureEx(backside, position, 0.f, 0.5f, WHITE);

    // Begin scissor mode to limit drawing to the panel area
    BeginScissorMode(panelX, panelY, panel_width, PANEL_HEIGHT);

    //static Texture2D background = LoadTexture("../../assets/background.png");
    //DrawTexture(background, panelX, panelYScroll, WHITE);

    // Dessin des cartes
    int row = 0;
    int col = 0;
    for (auto& card : deck)
    {
        if (!card->is_played()) break;
        const float x = static_cast<float>(panelX + col * (CARD_WIDTH + CARD_PADDING));
        const float y = static_cast<float>(panelYScroll + (row * (CARD_HEIGHT + CARD_PADDING)) - scrollY);
        DrawCard(card, x, y);

        col++;
        if (col >= max_cards_per_row)
        {
            col = 0;
            row++;
        }
        if (row >= PANEL_MAX_ROW) break;
    }

    // Dessiner un rectangle blanc à côté de la carte
    const float rectX = static_cast<float>(panelX + col * (CARD_WIDTH + CARD_PADDING));
    const float rectY = static_cast<float>(panelYScroll + (row * (CARD_HEIGHT + CARD_PADDING)) - scrollY);
    DrawRectangle(static_cast<int>(rectX), static_cast<int>(rectY), 120, 120, RAYWHITE);

    // End scissor mode to stop limiting drawing to the panel area
    EndScissorMode();
}

void DrawCard(std::unique_ptr<diamant::card>& card, const float x, const float y)
{
    const Texture2D& texture = card->get_texture();
    Color tint = RAYWHITE;

    if (diamant::relic_card* relic = dynamic_cast<diamant::relic_card*>(card.get()))
        if(relic->is_found()) tint = GRAY;

    DrawTextureEx(texture, {x,y}, 0.f, 0.5f, tint);

    if (diamant::treasure_card* treasure = dynamic_cast<diamant::treasure_card*>(card.get()))
    {
        const std::string current_diamonds = std::to_string(treasure->get_diamonds());
        const std::string initial_diamonds = std::to_string(treasure->get_initial_diamonds());
        const int posX = static_cast<int>(x + 20);
        const int posY = static_cast<int>(y + 25);
        DrawText(current_diamonds.c_str(), posX, posY, 25, WHITE);
        DrawText(initial_diamonds.c_str(), posX + 75, posY, 20, LIGHTGRAY);
    }
}

void DrawBotCircle(int centerX, int centerY, const diamant::player& player)
{
    Color color = (player.get_status() == diamant::player::PlayerStatus::Inactive) ? GRAY : GREEN;
    DrawCircle(centerX, centerY, GAME_BOT_CIRCLE_RADIUS, color);
    // Debug diamond count
    const std::string diamonds_text = std::to_string(player.get_score());
    DrawText(diamonds_text.c_str(), centerX - MeasureText(diamonds_text.c_str(), 20) / 2, centerY - 20, 20, BLACK);
}

void DrawBots(const std::vector<diamant::bot>& bots)
{
    const float screen_width = static_cast<float>(GetScreenWidth());

    for (int i = 0; i < bots.size(); ++i)
    {
        const diamant::bot& bot = bots.at(i);
        const int centerX = static_cast<int>(screen_width / (bots.size() + 1) * (i + 1));
        const int centerY = 120;
        DrawBotCircle(centerX, centerY, bot);

        const int font_size = 20;
        const int posX = centerX - MeasureText(bot.get_name().c_str(), font_size) / 2;
        const int posY = centerY - GAME_BOT_CIRCLE_RADIUS - font_size;
        DrawText(bot.get_name().c_str(), posX, posY, 20, BLACK);
    }
}