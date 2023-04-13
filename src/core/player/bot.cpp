#include "core/player/bot.h"

diamant::bot::bot(float moving_forward_probability) : player(), moving_forward_probability(moving_forward_probability) {}

void diamant::bot::play() {
    PlayerAction action = PlayerAction::MoveForward;
    switch (action)
    {
    case PlayerAction::MoveForward:
        // reduce moving_forward_probability
        diamant::player::continue_exploring();
        break;
    case PlayerAction::Leave:
        diamant::player::finish_exploring();
        break;
    default: break;
    }
}