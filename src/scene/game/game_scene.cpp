#include "scene/game/game_scene.h"

#include "utils/constants.h"
#include "utils/drawing.h"

#include <iostream>

game_scene::game_scene(scene_manager& scene_manager) : scene_manager_(scene_manager){}

void game_scene::update() 
{
    const float delta_time_sec = GetFrameTime();
    current_time_ms += static_cast<long>(delta_time_sec * 1000);
}

void game_scene::render()
{
    ClearBackground(RAYWHITE);
    DrawTextCenter("Game", 20, BLACK);

    DrawTimer(current_time_ms, 20, BLACK);

    DrawFPS(10, 10);
}