#include "scene/lobby/lobby_scene.h"
#include "utils/constants.h"
#include "utils/drawing.h"

#define RAYGUI_IMPLEMENTATION
#include <raygui.h>

void lobby_scene::update() {}

void lobby_scene::render()
{
    ClearBackground(RAYWHITE);
    if (GuiButton({ 50, 50, 150, 150 }, "Start Game"))
    {

    }
    DrawFPS(10, 10);
}