#pragma once

#include "core/player.h"

class bot : public player
{

public:
    Action play() const;

private:
    float moving_forward_probability = 0.8f;
};