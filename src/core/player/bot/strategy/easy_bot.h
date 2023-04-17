#pragma once

#include "core/player/bot/bot_strategy.h"
#include "core/player/player.h"

namespace diamant
{
    class easy_bot : public diamant::bot_strategy
    {
        public:
            PlayerAction next_action() override;
    };
}