#include "core/card/card.h"

using card = diamant::card;

diamant::card::card(card_type type) : type(type), played(false) {}
diamant::card::~card()
{
    UnloadTexture(card_texture);
}

diamant::card_type diamant::card::get_type() const { return type; }
Texture2D const& diamant::card::get_texture() const { return card_texture; }
bool diamant::card::is_played() const { return played; }

void diamant::card::set_played(bool played) { this->played = played; }