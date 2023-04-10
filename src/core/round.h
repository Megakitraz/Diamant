#pragma once

#include "core/card/deck.h"

class game_round
{
public:
    game_round(int id = 1);

    int get_id() const;

private:
    int id;
    deck deck_;
};