#include "core/round.h"
#include "core/card/treasure_card.h"
#include "utils/constants.h"
#include <assert.h>
#include <iostream>

diamant::round::round(int id) : id(id), last_played_card_index(-1) {}

void diamant::round::create_deck()
{
    for (int i = 0; i < GAME_TREASURE_CARD; i++)
        deck.emplace_back(std::make_unique<treasure_card>(i+1));

    shuffle_cards(deck);
}

void diamant::round::pick_card()
{
    const bool is_deck_empty = deck.empty();
    assert( !is_deck_empty && "Deck is empty." );

    auto card = deck[++last_played_card_index].get();
    card->set_played(true);
}

int diamant::round::get_id() const { return id; }
diamant::deck const& diamant::round::get_deck() const { return deck; }