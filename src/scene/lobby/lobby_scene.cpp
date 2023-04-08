#include "scene/lobby/lobby_scene.h"
#include "utils/constants.h"
#include "utils/drawing.h"

void lobby_scene::update() {}

void lobby_scene::render()
{
    ClearBackground(RAYWHITE);
    DrawTextCenter("Lobby", 20, BLACK);
    DrawFPS(10, 10);
}