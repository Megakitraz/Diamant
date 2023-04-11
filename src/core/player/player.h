#pragma once

class player
{

public:

    enum class Action
    {
        Waiting,
        MoveForward,
        Leave
    };

    player();

    // TODO: Need to find better names
    void continue_exploring();
    void finish_exploring(bool forced = false);

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

using Action = player::Action;