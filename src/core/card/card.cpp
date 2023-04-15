#include "core/card/card.h"
#include "core/game.h"
#include <iostream>

diamant::card::card() : played(false) {}

diamant::card::~card()
{
    UnloadTexture(card_texture);
}

void diamant::card::on_pick() { played = true; std::cout << "card: on_pick" << std::endl; }

Texture2D const& diamant::card::get_texture() const { return card_texture; }
bool diamant::card::is_played() const { return played; }