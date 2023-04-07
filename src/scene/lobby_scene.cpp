#include "scene/lobby_scene.h"
#include "utils/constants.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

lobby_scene::lobby_scene(lobby& lobby) : lobby_(lobby) {}

void lobby_scene::update()
{
    
}

void lobby_scene::render()
{
    ClearBackground(RAYWHITE);

    DrawFPS(10, 10);
}