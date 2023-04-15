#pragma once

#include <vector>
#include <memory>
#include "core/card/card.h"

namespace diamant {

    using deck = std::vector<std::unique_ptr<card>>;

    void fill_deck(deck& deck);
    void shuffle_deck(deck& deck);

}
