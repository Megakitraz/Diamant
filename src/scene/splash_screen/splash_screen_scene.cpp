#include "scene/splash_screen/splash_screen_scene.h"
#include "utils/drawing.h"

void splash_screen_scene::update() {
    const float delta_time_sec = GetFrameTime();
    current_time_ms += static_cast<int>(delta_time_sec * 1000);
    if (current_time_ms >= visible_for_ms) {
        //scene_manager::get().set_scene(scene_type::LOBBY);
    }
}

void splash_screen_scene::render()
{
    ClearBackground(RAYWHITE);
    DrawTextCenter("Splash screen", 20, BLACK);
    DrawFPS(10, 10);
}