#include "scene/game/game_scene.h"
#include "utils/constants.h"
#include "utils/drawing.h"
#include "utils/logger.h"
#include <raylib.h>
#include <raygui/raygui.h>

game_scene::game_scene(scene_manager& scene_manager) : scene_manager_(scene_manager) {}

void game_scene::activate()
{
    game_ = std::make_unique<game>();
}

void game_scene::update() 
{
    const float delta_time_sec = GetFrameTime();
    current_time_ms += static_cast<long>(delta_time_sec * 1000);

    //player& player = game_->get_player();
    //if (player.get_action() == Action::Waiting) return; // player didn't play yet
    // tant que le round n'est pas terminé => les bots jouent tout seul ?
    //std::cout << "he played" << std::endl;
}

void game_scene::render()
{
    ClearBackground(RAYWHITE);

    const int current_round_id = game_->get_round().get_id();
    const int round_count = game_->get_round_count();
    DrawRound(current_round_id, round_count, 20, BLACK);
    DrawTimer(current_time_ms, 20, BLACK);
    DrawFPS(10, 10);

    player& player = game_->get_player();
    if (player.get_action() == Action::Waiting)
    {
        if (GuiButton({ 500, 600, 100, 50 }, "Continue"))
        {
            player.continue_exploring();
        }

        if (GuiButton({ 650, 600, 100, 50 }, "Leave"))
        {
            player.finish_exploring();
        }
    }
    else
    {
        // need improvements, everyline is pure shit i hate it, it's disgusting...
        // maybe for_each in deck | round store lastest card played in deck
        deck const& deck = game_->get_round().get_deck();
        Texture2D const& texture = deck.front()->get_texture();
        DrawTextureEx(texture, {550,300}, 0.f, 0.5f, RAYWHITE);
    }
}