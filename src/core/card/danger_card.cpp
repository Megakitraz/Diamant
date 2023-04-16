#include "core/card/danger_card.h"
#include <iostream>

diamant::danger_card::danger_card(int id) : id(id)
{
    load_texture();
}

const int diamant::danger_card::get_id() const { return id; }

void diamant::danger_card::on_pick()
{
    diamant::card::on_pick();
    // Check if already played
}

void diamant::danger_card::on_left() {}

void diamant::danger_card::load_texture()
{
    // TODO: Add error handling
    const std::string texture_path = "../../assets/danger/" + std::to_string(id) + ".png";
    card_texture = LoadTexture(texture_path.c_str());
}