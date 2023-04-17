#pragma once

#include "core/player/player.h"
#include "core/player/bot/bot_strategy.h"
#include <memory>
#include <string>

namespace diamant
{
    class bot : public diamant::player
    {

    public:
        bot(const std::string& name, std::unique_ptr<diamant::bot_strategy> strategy);
        void play();

    private:
        std::unique_ptr<diamant::bot_strategy> strategy;
    };
}