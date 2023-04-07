#include "core/application.h"
#include <raylib.h>

#include "screen/lobby_screen.h"

constexpr int window_width = 1280;
constexpr int window_height = 720;
constexpr int target_fps = 60;

application::application()
{
    screen = std::make_unique<lobby_screen>(lobby);
}

void application::run()
{
    InitWindow(window_width, window_height, "Diamant");
	SetTargetFPS(target_fps);

	while (!WindowShouldClose())
	{
        BeginDrawing();
        screen->render();
        EndDrawing();
    }

    CloseWindow();
}