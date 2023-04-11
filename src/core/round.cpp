#include "round.h"
#include "core/card/treasure_card.h"

game_round::game_round(int id) : id(id)
{
    deck_.push_back(std::make_unique<treasure_card>(10));
}

int game_round::get_id() const { return id; }
deck const& game_round::get_deck() const { return deck_; }