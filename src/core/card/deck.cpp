#include "core/card/deck.h"
#include <random>
#include <algorithm>

void diamant::shuffle_cards(diamant::deck& deck)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(deck.begin(), deck.end(), gen);
}