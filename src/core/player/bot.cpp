#include "core/player/bot.h"

bot::bot(float moving_forward_probability) : moving_forward_probability(0.8f) {}

void bot::continue_exploring()
{
    player::continue_exploring();
    // reduce moving_forward_probability each time 
    // the bot move forward in the cavern
}

Action bot::play() const {
    return Action::MoveForward;
}