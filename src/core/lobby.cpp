#include "lobby.h"

int diamant::lobby::get_player_count() const { return player_count; }
int diamant::lobby::get_round_count() const { return round_count; }

void diamant::lobby::set_player_count(int new_player_count) { player_count = new_player_count; }
void diamant::lobby::set_round_count(int new_round_count) { round_count = new_round_count; }