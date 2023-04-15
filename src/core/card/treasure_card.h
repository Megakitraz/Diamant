#pragma once

#include "core/card/card.h"

namespace diamant {

    class treasure_card : public diamant::card
    {
        public:
            treasure_card(int diamonds);

            const int get_diamonds() const;

            void load_texture() override;
            void play() override;

        private:
            int diamonds;

    };

}