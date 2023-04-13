#include "core/player/bot.h"

diamant::bot::bot(float moving_forward_probability) : player(), moving_forward_probability(0.8f) {}

void diamant::bot::continue_exploring()
{
    player::continue_exploring();
    // reduce moving_forward_probability each time 
    // the bot move forward in the cavern
}

PlayerAction diamant::bot::play() const {
    return PlayerAction::MoveForward;
}