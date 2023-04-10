#include "core/player.h"

player::player() : score(0), in_exploration(true), action(Action::Waiting) {}

void player::set_score(int score) { this->score = score; }
void player::set_exploring(bool in_exploration) { this->in_exploration = in_exploration; }
void player::set_action(Action action) { this->action = action; }

int player::get_score() const { return score; }
bool player::is_exploring() const{ return in_exploration; }
Action player::get_action() const { return action; }