#include "scene/lobby/lobby_scene.h"
#include "utils/constants.h"
#include "utils/drawing.h"
#include <raygui/raygui.h>

lobby_scene::lobby_scene(scene_manager& scene_manager) : scene_manager_(scene_manager){}

void lobby_scene::activate()
{
    lobby = std::make_unique<diamant::lobby>();
}

void lobby_scene::update() {}

void lobby_scene::render()
{
    ClearBackground(RAYWHITE);
    if (GuiButton({ 50, 50, 150, 150 }, "Start Game"))
    {
        scene_manager_.switch_to("game");
    }
    DrawFPS(10, 10);
}