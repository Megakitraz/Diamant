#include "core/card/deck.h"
#include "utils/constants.h"
#include "core/card/treasure_card.h"
#include <random>
#include <algorithm>

void diamant::fill_deck(diamant::deck& deck)
{
    for (int i = 0; i < GAME_TREASURE_CARD; i++)
        deck.emplace_back(std::make_unique<treasure_card>(i+1));
}

void diamant::shuffle_deck(diamant::deck& deck)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(deck.begin(), deck.end(), gen);
}