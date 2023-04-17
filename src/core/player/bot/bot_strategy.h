#pragma once

#include "core/player/player.h"

namespace diamant
{
    class bot_strategy
    {
        public:
            virtual PlayerAction next_action() = 0;
    };
}