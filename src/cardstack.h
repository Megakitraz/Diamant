#pragma once

#include "card.h"

class card_stack
{
public:
	void shuffle_cards(std::vector<card> cards);
	void pick_random_cards(std::vector<card> cards);
};