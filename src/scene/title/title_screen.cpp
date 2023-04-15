#include "scene/title/title_screen.h"
#include "utils/constants.h"
#include "utils/drawing.h"
#include <raygui/raygui.h>

title_screen::title_screen(scene_manager& scene_manager) : scene_manager_(scene_manager){}

void title_screen::activate() {}

void title_screen::update() {}

void title_screen::render()
{
    ClearBackground(RAYWHITE);
    if (GuiButton({ 50, 50, 150, 150 }, "Start Game"))
    {
        scene_manager_.switch_to("game");
    }
    DrawFPS(10, 10);
}