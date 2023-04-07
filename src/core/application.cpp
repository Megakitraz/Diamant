#include "core/application.h"
#include <raylib.h>

#include "scene/lobby_scene.h"

constexpr int window_width = 1280;
constexpr int window_height = 720;
constexpr int target_fps = 60;

application::application()
{
    scene = std::make_unique<lobby_scene>(lobby);
}

void application::run()
{
    InitWindow(window_width, window_height, "Diamant");
	SetTargetFPS(target_fps);

	while (!WindowShouldClose())
	{
        scene->update();
        BeginDrawing();
        scene->render();
        EndDrawing();
    }

    CloseWindow();
}