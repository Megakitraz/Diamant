#pragma once

#include "core/action.h"

class player
{

public:
    player();

    void set_score(int score);
    void set_exploring(bool is_exploring);
    void set_action(Action action);

    int get_score() const;
    bool is_exploring() const;
    Action get_action() const;

private:
    int score;
    bool in_exploration;
    Action action;
};