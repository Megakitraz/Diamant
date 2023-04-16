#pragma once

#include "core/card/card.h"

namespace diamant {

    class relic_card : public diamant::card
    {
        public:
            relic_card();

            bool is_found() const;

            void load_texture() override;
            void on_left() override;

        private:
            bool found;
    };

}