#include "core/player/player.h"

diamant::player::player() : score(0), in_exploration(true), status(PlayerStatus::Inactive) {}

void diamant::player::continue_exploring()
{
    last_action = PlayerAction::MoveForward;
}

void diamant::player::finish_exploring(bool forced)
{
    last_action = PlayerAction::Leave;
    status = PlayerStatus::Inactive;
    in_exploration = false;
    //if !forced
    //  save score in chest
}

void diamant::player::set_score(int score) { this->score = score; }
void diamant::player::set_exploring(bool in_exploration) { this->in_exploration = in_exploration; }
void diamant::player::set_status(PlayerStatus status) { this->status = status; }

int diamant::player::get_score() const { return score; }
bool diamant::player::is_exploring() const{ return in_exploration; }
PlayerStatus diamant::player::get_status() const { return status; }