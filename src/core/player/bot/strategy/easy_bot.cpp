#include "core/player/bot/strategy/easy_bot.h"
#include <random>
#include <iostream>

PlayerAction diamant::easy_bot::easy_bot::next_action()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 1);
    int choice = dis(gen);

    if (choice)
        PlayerAction::MoveForward;

    return PlayerAction::Leave;
}