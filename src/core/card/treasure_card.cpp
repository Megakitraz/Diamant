#include "core/card/treasure_card.h"
#include <string>

treasure_card::treasure_card(int diamonds) : 
    card(diamant::card_type::Treasure), 
    diamonds(diamonds)
{
    load_texture();
}


void treasure_card::load_texture()
{
    // TODO: Add error handling
    const std::string texture_path = "../../assets/treasure/" + std::to_string(diamonds) + ".png";
    card_texture = LoadTexture(texture_path.c_str());
}