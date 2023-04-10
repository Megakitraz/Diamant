#pragma once

#include <raylib.h>
#include <string>

void DrawTextCenter(std::string const& text, int fontSize, Color color);
void DrawTimer(long time_ms, int fontSize, Color color);
void DrawRound(int current, int max, int fontSize, Color color);