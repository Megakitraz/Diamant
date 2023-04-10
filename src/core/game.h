#pragma once

#include <vector>
#include "core/player.h"
#include "core/bot.h"
#include "core/round.h"

class game
{

public:
     game();

     void next_round();

     player& get_player();
     std::vector<bot>& get_bots();
     game_round& get_round();
     int get_round_count() const;

private:
     player player_;
     std::vector<bot> bots;
     game_round round_;

     int round_count;
};