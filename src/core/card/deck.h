#pragma once

#include <vector>
#include <memory>
#include "core/card/card.h"

namespace diamant {

    using deck = std::vector<std::unique_ptr<card>>;

    void shuffle_cards(deck& deck);

}
