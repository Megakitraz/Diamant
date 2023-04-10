#include "scene/game/game_scene.h"

#include "utils/constants.h"
#include "utils/drawing.h"
#include <raygui/raygui.h>

#include <iostream>

game_scene::game_scene(scene_manager& scene_manager) : scene_manager_(scene_manager) {}

void game_scene::update() 
{
    const float delta_time_sec = GetFrameTime();
    current_time_ms += static_cast<long>(delta_time_sec * 1000);

    player& player = game_.get_player();
    if (player.get_action() == Action::Waiting) return; // player didn't play yet
    // tant que le round n'est pas terminé => les bots jouent tout seul ?
    std::cout << "he played" << std::endl;
    player.set_action(Action::Waiting);
}

void game_scene::render()
{
    ClearBackground(RAYWHITE);

    DrawFPS(10, 10);
    DrawTimer(current_time_ms, 20, BLACK);

    const int current_round_id = game_.get_round().get_id();
    const int round_count = game_.get_round_count();
    DrawRound(current_round_id, round_count, 20, BLACK);

    player& player = game_.get_player();
    if (player.get_action() == Action::Waiting)
    {
        if (GuiButton({ 200, 200, 100, 50 }, "Continue"))
            player.set_action(Action::MoveForward);

        if (GuiButton({ 400, 200, 100, 50 }, "Leave"))
        {
            player.set_action(Action::Leave);
            player.set_exploring(false);
        }
    }
}