#pragma once

#include "core/player/player.h"

class bot : public player
{

public:
    bot(float moving_forward_probability);

    void continue_exploring();
    Action play() const;

private:
    float moving_forward_probability;
};