#pragma once

#include "core/card/card.h"

class treasure_card : public diamant::card
{
    public:
        treasure_card(int diamonds);
        void load_texture() override;

    private:
        int diamonds;

};