#pragma once

#include "core/player/bot/bot_strategy.h"
#include "core/player/player.h"

namespace diamant
{
    class medium_bot : public diamant::bot_strategy
    {
        public:
            PlayerAction next_action() override;

        private:
            float moving_forward_probability = 1.f;
    };
}