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
    diamant::game& game = diamant::game::instance();
    game.start();
}

void game_scene::update() 
{
    const float delta_time_sec = GetFrameTime();
    current_time_ms += static_cast<long>(delta_time_sec * 1000);

    diamant::game& game = diamant::game::instance();
    diamant::player& player = game.get_player();
    if (player.get_status() == PlayerStatus::WaitingForNextMove) return; // player didn't play yet
    std::vector<diamant::bot>& bots = game.get_bots();
    for(auto& bot : bots)
    {
        if (bot.get_status() == PlayerStatus::Inactive) continue;
        bot.play();
    }
    game.get_round().pick_card();
    player.set_status(PlayerStatus::WaitingForNextMove);
}

void game_scene::render()
{
    ClearBackground(RAYWHITE);
    
    diamant::game& game = diamant::game::instance();
    const int current_round_id = game.get_round().get_id();
    const int round_count = game.get_round_count();
    DrawRound(current_round_id, round_count, 20, BLACK);
    DrawTimer(current_time_ms, 20, BLACK);
    DrawFPS(10, 10);

    const diamant::deck& deck = game.get_round().get_deck();
    DrawCards(deck);

    diamant::player& player = game.get_player();
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
 
    DrawBots(game.get_bots());
}