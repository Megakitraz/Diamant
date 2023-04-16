#include "core/player/player.h"

diamant::player::player(const std::string& name) : name(name), score(0), status(PlayerStatus::Inactive) {}

void diamant::player::continue_exploring()
{
    last_action = PlayerAction::MoveForward;
    status = PlayerStatus::WaitingForIsTurn;
}

void diamant::player::finish_exploring(bool forced)
{
    last_action = PlayerAction::Leave;
    status = PlayerStatus::Inactive;
    //if !forced
    //  save score in chest
}

void diamant::player::add_score(int increment) { score += increment; }
void diamant::player::reset_score() { score = 0; }
void diamant::player::set_status(PlayerStatus status) { this->status = status; }
void diamant::player::set_last_action(PlayerAction action) { this->last_action = action; }

const std::string& diamant::player::get_name() const { return name; }
const int diamant::player::get_score() const { return score; }
diamant::chest& diamant::player::get_chest() { return chest; }
const PlayerStatus diamant::player::get_status() const { return status; }
const PlayerAction diamant::player::get_last_action() const { return last_action; }