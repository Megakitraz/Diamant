#pragma once

#include "core/player/player.h"
#include "core/player/bot.h"
#include "core/card/deck.h"
#include <vector>
#include <raylib.h>
#include <string>

// Helper raylib functions
void DrawTextCenter(std::string const& text, int fontSize, Color color);

// Helper game functions
void DrawTimer(long time_ms, int fontSize, Color color);
void DrawRound(int current, int max, int fontSize, Color color);
void DrawCards(const diamant::deck& deck);
void DrawBots(const std::vector<diamant::bot>& bots);
void DrawBotCircle(int centerX, int centerY, const diamant::player& player);