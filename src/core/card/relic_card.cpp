#include "core/card/relic_card.h"
#include <iostream>

diamant::relic_card::relic_card()
{
    load_texture();
}

void diamant::relic_card::on_left() 
{

}

void diamant::relic_card::load_texture()
{
    // TODO: Add error handling
    const std::string texture_path = "../../assets/relic.png";
    card_texture = LoadTexture(texture_path.c_str());
}