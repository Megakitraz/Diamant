#include "round.h"

game_round::game_round(int id) : id(id) {}

int game_round::get_id() const { return id; }