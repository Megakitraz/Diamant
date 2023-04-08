#include "core/application.h"
#include "scene/splash_screen/splash_screen_scene.h"
#include "scene/lobby/lobby_scene.h"
#include "utils/constants.h"
#include <raylib.h>

application::application()
{
    scene_manager& scene_manager = scene_manager::instance();
    scene_manager.add_scene("splash_screen", std::make_unique<splash_screen_scene>(), true);
    scene_manager.add_scene("lobby", std::make_unique<lobby_scene>());
}

void application::run()
{
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Diamant");
	SetTargetFPS(WINDOW_TARGET_FPS);

	while (!WindowShouldClose())
	{
        scene& scene = scene_manager::instance().get_current_scene();

        scene.update();

        BeginDrawing();
        scene.render();
        EndDrawing();
    }

    CloseWindow();
}