#pragma once

#include "core/card/deck.h"

namespace diamant
{

    class round
    {
    public:
        round(int id = 1);

        void create_deck();
        void pick_card();

        int get_id() const;
        deck const& get_deck() const;

    private: 
        int id;
        diamant::deck deck;
    };

}