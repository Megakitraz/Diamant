#include "scenes/splash_screen/splash_screen_scene.h"
#include "utils/drawing.h"
#include "scenes/scene_manager.h"

splash_screen_scene::splash_screen_scene(scene_manager& scene_manager) : scene_manager_(scene_manager){}

void splash_screen_scene::activate() {}

void splash_screen_scene::update() {
    const float delta_time_sec = GetFrameTime();
    current_time_ms += static_cast<long>(delta_time_sec * 1000);
    if (current_time_ms >= visible_for_ms) {
        scene_manager_.switch_to("title");
    }
}

void splash_screen_scene::render()
{
    ClearBackground(RAYWHITE);
    DrawTextCenter("Splash screen", 20, BLACK);
    DrawFPS(10, 10);
}