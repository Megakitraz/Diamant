#include "core/player/bot/bot.h"
#include "core/player/player.h"
#include <iostream>

diamant::bot::bot(const std::string& name, std::unique_ptr<bot_strategy> strategy) : player(name), strategy(std::move(strategy)) {}

void diamant::bot::play() 
{
    PlayerAction next_action = strategy->next_action();
    if (next_action == PlayerAction::Leave)
        diamant::player::finish_exploring();
    else
        diamant::player::continue_exploring();
}