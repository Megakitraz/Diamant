#include "core/player/bot/strategy/medium_bot.h"
#include <random>
#include <iostream>

PlayerAction diamant::medium_bot::medium_bot::next_action()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::discrete_distribution<> dist({moving_forward_probability,1-moving_forward_probability});
    int choice = dist(gen);

    if (choice == 0)
    {
        moving_forward_probability -= 0.1f;
        return PlayerAction::MoveForward;
    }

    moving_forward_probability = 1.f;
    return PlayerAction::Leave;
}