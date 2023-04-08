#include "lobby.h"

#include <iostream>

int lobby::get_player_count() const { return player_count; }
int lobby::get_round_count() const { return round_count; }

void lobby::set_player_count(int new_player_count) { player_count = new_player_count; }
void lobby::set_round_count(int new_round_count) { round_count = new_round_count; }