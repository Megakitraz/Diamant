#pragma once

#include "core/player/player.h"
#include <random>
#include <string>

namespace diamant
{

    class bot : public diamant::player
    {

    public:
        bot(const std::string& name, float moving_forward_probability);
        void play();

    private:
        float moving_forward_probability;
    };

}