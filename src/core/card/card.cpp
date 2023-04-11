#include "core/card/card.h"

card::card(card_type type) : type(type) {}
card::~card()
{
    UnloadTexture(card_texture);
}

card_type card::get_type() const { return type; }
Texture2D const& card::get_texture() const { return card_texture; }