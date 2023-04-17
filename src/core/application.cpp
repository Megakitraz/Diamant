#include "core/application.h"
#include "scenes/splash_screen/splash_screen_scene.h"
#include "scenes/title/title_screen.h"
#include "scenes/game/game_scene.h"
#include "utils/constants.h"
#include <raylib.h>

application::application()
{
    // Remove raylib logs
    SetTraceLogLevel(LOG_NONE);

    scene_manager_.add_scene("splash_screen", std::make_unique<splash_screen_scene>(scene_manager_), true);
    scene_manager_.add_scene("title", std::make_unique<title_screen>(scene_manager_));
    scene_manager_.add_scene("game", std::make_unique<game_scene>(scene_manager_));
}

void application::run()
{
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Diamant");
	SetTargetFPS(WINDOW_TARGET_FPS);

	while (!WindowShouldClose())
	{
        scene& scene = scene_manager_.get_current_scene();

        scene.update();

        BeginDrawing();
        scene.render();
        EndDrawing();
    }

    CloseWindow();
}