#pragma once

#include "core/player.h"

class bot : public player
{

public:
    bot(float moving_forward_probability);
    Action play() const;

private:
    float moving_forward_probability;
};