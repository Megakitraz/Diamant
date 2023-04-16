#include "core/card/deck.h"
#include "utils/constants.h"
#include "core/card/treasure_card.h"
#include "core/card/danger_card.h"
#include "core/card/relic_card.h"
#include <random>
#include <algorithm>

void diamant::fill_deck(diamant::deck& deck)
{
    for (int i = 0; i < CARD_TREASURE_COUNT; ++i)
        deck.emplace_back(std::make_unique<treasure_card>(i+1));

    for (int i = 0; i < CARD_DANGER_TYPE; ++i)
        for (int j = 0; j < CARD_DANGER_OCCURENCE; ++j)
            deck.emplace_back(std::make_unique<danger_card>(i+1));
    
    for (int i = 0; i < CARD_RELIC_COUNT; ++i)
        deck.emplace_back(std::make_unique<relic_card>());
}

void diamant::shuffle_deck(diamant::deck& deck)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(deck.begin(), deck.end(), gen);
}