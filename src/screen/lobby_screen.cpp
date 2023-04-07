#include "screen/lobby_screen.h"
#include "utils/constants.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

lobby_screen::lobby_screen(lobby& lobby) : lobby_(lobby) {}

void lobby_screen::render()
{
    ClearBackground(RAYWHITE);

    DrawFPS(10, 10);
}