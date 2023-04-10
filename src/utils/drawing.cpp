#include "utils/drawing.h"
#include "utils/time.h"

void DrawTextCenter(std::string const& text, int fontSize, Color color)
{
    const int text_width = MeasureText(text.c_str(), fontSize);
    const int x = (GetScreenWidth() - text_width) / 2;
    const int y = GetScreenHeight() / 2;
    DrawText(text.c_str(), x, y, fontSize, color);
}

void DrawTimer(long time_ms, int fontSize, Color color)
{
    const std::string time = time_to_string(time_ms);
    const int text_width = MeasureText(time.c_str(), fontSize);
    const int x = (GetScreenWidth() - text_width) - 10;
    const int y = 10;
    DrawText(time.c_str(), x, y, fontSize, color);
}