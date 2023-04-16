#include "scene/game/game_scene.h"
#include "core/card/card.h"
#include "utils/constants.h"
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

    // Affichage des choix pour le joueur
    diamant::player& player = game.get_player();
    if (player.get_status() == PlayerStatus::WaitingForNextMove)
    {
        if (GuiButton({ (1280 - 200) / 2, 600, 100, 50 }, "Continue"))
            player.continue_exploring();

        if (GuiButton({ (1280 + 50) / 2, 600, 100, 50 }, "Leave"))
            player.finish_exploring();
    }

    // Affichage du score d'exploration du joueur
    const int fontSize = 20;
    const char* scoreText = TextFormat("Score d'exploration : %d", player.get_score());
    const int textWidth = MeasureText(scoreText, fontSize);
    DrawText(scoreText, (1280 - textWidth) / 2, 720 - fontSize - 10, fontSize, BLACK);

    // Affichage des score et status des bots
    DrawBots(game.get_bots());
}