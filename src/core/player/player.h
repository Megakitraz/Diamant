#pragma once

namespace diamant
{

    class player
    {

    public:

        // TODO: Need to find better names
        enum class PlayerStatus
        {
            Inactive,
            WaitingForIsTurn,
            WaitingForNextMove,
        };

        // TODO: Maybe useless
        enum class PlayerAction
        {
            None,
            MoveForward,
            Leave,
        };

        player();

        // TODO: Need to find better names
        void continue_exploring();
        void finish_exploring(bool forced = false);

        void set_score(int score);
        void set_exploring(bool is_exploring);
        void set_status(PlayerStatus action);

        int get_score() const;
        bool is_exploring() const;
        PlayerStatus get_status() const;

    private:
        int score;
        bool in_exploration;
        PlayerStatus status;
        PlayerAction last_action;
    };

}

using PlayerStatus = diamant::player::PlayerStatus;
using PlayerAction = diamant::player::PlayerAction;