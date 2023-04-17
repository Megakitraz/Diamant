#pragma once

#include "core/chest.h"
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

        void add_score(int increment);
        void reset_score();

        void set_score(int score);
        void set_status(PlayerStatus action);
        void set_last_action(PlayerAction action);

        const std::string& get_name() const;
        const int get_score() const;
        diamant::chest& get_chest();
        const PlayerStatus get_status() const;
        const PlayerAction get_last_action() const;

    private:
        std::string name;
        int score;
        diamant::chest chest;
        PlayerStatus status;
        PlayerAction last_action;
    };
}


using PlayerStatus = diamant::player::PlayerStatus;
using PlayerAction = diamant::player::PlayerAction;