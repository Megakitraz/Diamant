#pragma once

#include "core/player/player.h"

namespace diamant
{

    class bot : public diamant::player
    {

    public:
        bot(float moving_forward_probability);
        void play();

    private:
        float moving_forward_probability;
    };

}