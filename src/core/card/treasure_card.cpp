#include "core/card/treasure_card.h"
#include "core/game.h"
#include <string>
#include <iostream>

treasure_card::treasure_card(int diamonds) : 
    diamonds(diamonds)
{
    load_texture();
}

void treasure_card::play()
{
    diamant::card::play();
    std::cout << "play(): treasure card" << std::endl;
    std::cout << "  |- initial diamonds: " << diamonds << std::endl;

    diamant::game& game = diamant::game::instance();
    const int active_players = game.get_active_players();
    std::cout << "  |- active players: " << active_players << std::endl;

    const auto [diamonds_per_player, remainder] = std::div(diamonds, active_players);
    diamonds = remainder;
    std::cout << "  |- per/player: " << diamonds_per_player << " | remainer: " << remainder << std::endl;
}

void treasure_card::load_texture()
{
    // TODO: Add error handling
    const std::string texture_path = "../../assets/treasure.png";
    card_texture = LoadTexture(texture_path.c_str());
}