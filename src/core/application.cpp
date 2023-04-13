#include "core/application.h"
#include "scene/splash_screen/splash_screen_scene.h"
#include "scene/lobby/lobby_scene.h"
#include "scene/game/game_scene.h"
#include "utils/constants.h"
#include "utils/logger.h"
#include <raylib.h>

application::application()
{
    scene_manager_.add_scene("splash_screen", std::make_unique<splash_screen_scene>(scene_manager_), true);
    scene_manager_.add_scene("lobby", std::make_unique<lobby_scene>(scene_manager_));
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