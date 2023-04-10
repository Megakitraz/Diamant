#include "core/game.h"

game::game() : round_count(5) {}

void game::next_round()
{
    //round next(round_.id + 1);
    //next_round.deck = create_deck().shuffle();
    //round_ = std::move(next);
}

player& game::get_player(){ return player_; }
std::vector<bot>& game::get_bots() { return bots; }
game_round& game::get_round() { return round_; }
int game::get_round_count() const { return round_count; }