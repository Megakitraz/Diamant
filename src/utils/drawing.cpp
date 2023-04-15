#include "utils/drawing.h"
#include "utils/time.h"
#include "utils/constants.h"
#include "core/card/treasure_card.h"

void DrawTextCenter(std::string const& text, int fontSize, Color color)
{
    const int text_width = MeasureText(text.c_str(), fontSize);
    const int x = (GetScreenWidth() - text_width) / 2;
    const int y = GetScreenHeight() / 2;
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

void DrawCards(const diamant::deck& deck)
{
    int idx = 0;
    for (auto& card : deck)
    {
        if (!card->is_played()) break;
        const Texture2D& texture = card->get_texture();
        const float x = static_cast<float>(100 + (idx++ * 130));
        const float y = static_cast<float>(300);
        DrawTextureEx(texture, {x,y}, 0.f, 0.5f, RAYWHITE);

        if (diamant::treasure_card* treasure = dynamic_cast<diamant::treasure_card*>(card.get()))
        {
            if (treasure->get_diamonds() == 0) return;
            const std::string diamonds = std::to_string(treasure->get_diamonds());
            const int posX = static_cast<int>(x + 20);
            const int posY = static_cast<int>(y + 20);
            DrawText(diamonds.c_str(), posX, posY, 25, WHITE);
        }
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