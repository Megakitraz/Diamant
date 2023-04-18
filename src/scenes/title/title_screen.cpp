#include "scenes/title/title_screen.h"
#include "utils/constants.h"
#include "utils/drawing.h"
#include <raylib.h>
#include <raygui/raygui.h>

title_screen::title_screen(scene_manager& scene_manager) : scene_manager_(scene_manager){}

void title_screen::activate() {}

void title_screen::update() {}

void title_screen::render()
{
    ClearBackground(RAYWHITE);

    static Texture2D diamant_logo = LoadTexture("../../assets/diamant.png");
    static Vector2 position = { WINDOW_WIDTH / 2 - diamant_logo.width / 2, 150 };
    DrawTextureEx(diamant_logo, position, 0.f, 1.f, WHITE);

    if (GuiButton({650,400,200,50}, "New Game"))
        scene_manager_.switch_to("game");

    if (GuiButton({650,500,200,50}, "Quit"))
        CloseWindow();
}