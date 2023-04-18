#include "scenes/game/game_scene.h"
#include "core/card/card.h"
#include "utils/drawing.h"
#include <raylib.h>
#include <raygui/raygui.h>
#include <algorithm>
#include <iostream>
#include <chrono>
#include <thread>

game_scene::game_scene(scene_manager& scene_manager) : scene_manager_(scene_manager) {}

void game_scene::activate() 
{
    diamant::game& game = diamant::game::instance();
    game.new_round();
}

void game_scene::update() 
{
    const float delta_time_sec = GetFrameTime();
    current_time_ms += static_cast<long>(delta_time_sec * 1000);

    diamant::game& game = diamant::game::instance();
    diamant::player& player = game.get_player();
    if (player.get_status() == PlayerStatus::WaitingForNextMove) return; // player didn't play yet
    if (game.is_round_finished()) return; // popup before next round starts

    if (sleed_for_sec > 0)
    {
        sleed_for_sec -= delta_time_sec;
        return;
    }

    std::vector<diamant::bot>& bots = game.get_bots();
    for(auto& bot : bots)
    {
        if (bot.get_status() == PlayerStatus::Inactive) continue;
        bot.play();
    }
    sleed_for_sec = GAME_TURN_WAIT;
    game.end_turn();
}

void game_scene::render()
{
    ClearBackground(RAYWHITE);

    diamant::game& game = diamant::game::instance();
    const int current_round_id = game.get_current_round_id();
    const int round_count = game.get_round_count();
    DrawRound(current_round_id, round_count, 20, BLACK);
    DrawTimer(current_time_ms, 20, BLACK);

    diamant::deck& deck = game.get_deck();
    DrawCards(deck);

    // Affichage du score d'exploration du joueur
    diamant::player& player = game.get_player();
    const char* player_score_text = TextFormat("Score d'exploration : %d", player.get_score());
    DrawTextCenterX(player_score_text, WINDOW_HEIGHT - 60, 20, BLACK);

    // Affichage du score d'exploration du joueur
    const char* player_chest_score_text = TextFormat("Coffre : %d", player.get_chest().get());
    DrawTextCenterX(player_chest_score_text, WINDOW_HEIGHT - 30, 20, BLACK);

    // Affichage des score et status des bots
    DrawBots(game.get_bots());

    if(game.is_round_finished())
    {
        const int action = GuiMessageBox({20,20,250,100}, "End of round", "Expedition is over, back to camp.", "Continue");
        if(action == 0 || action == 1)
            game.end_round();
    }
    else
    {
        // Affichage des choix pour le joueur
        if (player.get_status() == PlayerStatus::WaitingForNextMove)
        {
            if (GuiButton({ (WINDOW_WIDTH - 300) / 2, 670, 100, 50 }, "Continue"))
                player.continue_exploring();

            if (GuiButton({ (WINDOW_WIDTH + 50) / 2, 670, 100, 50 }, "Leave"))
                player.finish_exploring();
        }    
    }
}