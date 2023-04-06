#include "application.h"
#include "raylib.h"

application::application(std::string_view title, std::uint16_t window_width, std::uint16_t window_height) :
	title(title),
	window_width(window_width),
	window_height(window_height)
{}

application& application::get_application()
{
	static application instance(TITLE, WINDOW_WIDTH, WINDOW_HEIGHT);
	return instance;
}

void application::run()
{
	InitWindow(800, 450, "raylib [core] example - basic window");

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
    }

    CloseWindow();
}