#pragma once

#include <string>

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

        enum class PlayerAction
        {
            None,
            MoveForward,
            Leave,
        };

        player(const std::string& name);

        // TODO: Need to find better names
        void continue_exploring();
        void finish_exploring(bool forced = false);

        void set_score(int score);
        void set_exploring(bool is_exploring);
        void set_status(PlayerStatus action);

        const std::string& get_name() const;
        const int get_score() const;
        const bool is_exploring() const;
        const PlayerStatus get_status() const;
        const PlayerAction get_last_action() const;

    private:
        std::string name;
        int score;
        bool in_exploration;
        PlayerStatus status;
        PlayerAction last_action;
    };

}

using PlayerStatus = diamant::player::PlayerStatus;
using PlayerAction = diamant::player::PlayerAction;