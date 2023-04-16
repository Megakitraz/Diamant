#pragma once

#include "core/card/card.h"

namespace diamant {

    class danger_card : public diamant::card
    {
        public:
            danger_card(int id);

            const int get_id() const;

            void load_texture() override;
            void on_pick() override;
            void on_left() override;

        private:
            int id;

    };

}