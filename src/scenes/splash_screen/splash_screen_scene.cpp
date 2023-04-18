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
    
    static Texture2D uqac_logo = LoadTexture("../../assets/uqac.png");
    static Vector2 position = { WINDOW_WIDTH / 2 - uqac_logo.width / 2, WINDOW_HEIGHT / 2 - uqac_logo.height / 2 };
    DrawTextureEx(uqac_logo, position, 0.f, 1.f, WHITE);

    DrawTextCenterX("Lucas DESHAYES  Louan OURVOUAI  Victor ENJALBERT", WINDOW_HEIGHT - 50, 20, BLACK);
}