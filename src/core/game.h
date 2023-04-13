#pragma once

#include <vector>
#include "core/player/player.h"
#include "core/player/bot.h"
#include "core/round.h"

namespace diamant
{

     class game
     {

     public:
          game();

          void start();
          void next_round();

          diamant::player& get_player();
          std::vector<bot>& get_bots();
          diamant::round& get_round();

          int get_round_count() const;

     private:
          diamant::player player;
          std::vector<bot> bots;
          diamant::round round;

          int round_count;
     };

}
