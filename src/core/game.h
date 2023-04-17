#pragma once

#include "core/player/player.h"
#include "core/player/bot/bot.h"
#include "core/card/deck.h"
#include "utils/singleton.h"
#include <vector>
#include <unordered_map>

namespace diamant
{
     class game : public singleton<game>
     {

     public:
          game();

          void new_round();
          void new_turn();
          void end_round();
          void end_turn();

          int get_active_players() const;
          std::vector<diamant::player*> get_gone_players();

          int add_danger(int id);

          diamant::player& get_player();
          std::vector<diamant::bot>& get_bots();
          diamant::deck& get_deck();
          const int get_relic_found() const;
          const int get_round_count() const;
          const int get_current_round_id() const;

     private:
          diamant::player player;
          std::vector<bot> bots;
          
          std::unordered_map<int, int> danger_occurence;
          int relic_found;

          diamant::deck deck;
          int last_played_card_index;

          int round_count;
          int current_round_id;
     };
}
