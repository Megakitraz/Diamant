#include "scene/game/game_scene.h"
#include "core/card/card.h"
#include "utils/constants.h"
#include "utils/drawing.h"
#include <raylib.h>
#include <raygui/raygui.h>
#include <algorithm>
#include <iostream>

game_scene::game_scene(scene_manager& scene_manager) : scene_manager_(scene_manager) {}

void game_scene::activate()
{
    game = std::make_unique<diamant::game>();
    game->start();
}

void game_scene::update() 
{
    const float delta_time_sec = GetFrameTime();
    current_time_ms += static_cast<long>(delta_time_sec * 1000);

    diamant::player& player = game->get_player();
    if (player.get_status() == PlayerStatus::WaitingForNextMove) return; // player didn't play yet
    std::vector<diamant::bot>& bots = game->get_bots();
    for(auto& bot : bots)
    {
        if (bot.get_status() == PlayerStatus::Inactive) continue;
        bot.play();
    }
    game->get_round().pick_card();
    player.set_status(PlayerStatus::WaitingForNextMove);
}

void game_scene::render()
{
    ClearBackground(RAYWHITE);

    const int current_round_id = game->get_round().get_id();
    const int round_count = game->get_round_count();
    DrawRound(current_round_id, round_count, 20, BLACK);
    DrawTimer(current_time_ms, 20, BLACK);
    DrawFPS(10, 10);

    int idx = 0;
    const diamant::deck& deck = game->get_round().get_deck();
    for (const auto& card : deck)
    {
        if (!card->is_played()) break;
        const Texture2D& texture = card->get_texture();
        const float x = static_cast<float>(100 + (idx++ * 130));
        const float y = static_cast<float>(300);
        DrawTextureEx(texture, {x,y}, 0.f, 0.5f, RAYWHITE);
    }

    diamant::player& player = game->get_player();
    if (player.get_status() == PlayerStatus::WaitingForNextMove)
    {
        if (GuiButton({ 500, 600, 100, 50 }, "Continue"))
        {
            player.continue_exploring();
            player.set_status(PlayerStatus::WaitingForIsTurn);
            std::cout << "player continue" << std::endl;
        }

        if (GuiButton({ 650, 600, 100, 50 }, "Leave")){
            player.finish_exploring();
            player.set_status(PlayerStatus::WaitingForIsTurn);
            std::cout << "player leave" << std::endl;
        }
    }
}