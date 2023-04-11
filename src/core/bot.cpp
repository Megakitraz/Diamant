#include "core/bot.h"

bot::bot(float moving_forward_probability) : moving_forward_probability(0.8f) {}

Action bot::play() const {
    return Action::MoveForward;
}