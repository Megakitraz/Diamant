#include "core/card/treasure_card.h"
#include "core/game.h"
#include <string>

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
    
    std::vector<diamant::bot> &bots = game.get_bots();

    for (size_t i = 0; i < bots.size(); i++)
    {
      if (bots[i].get_status() != diamant::player::PlayerStatus::Inactive)
      {
        std::cout << " bot : " << i << " old score : " << bots[i].get_score() << std::endl;
        bots[i].set_score(bots[i].get_score()+diamonds_per_player);
        std::cout << " bot : " << i << " new score : " << bots[i].get_score() << std::endl;
      }
    }
    if (game.get_player().get_status() != diamant::player::PlayerStatus::Inactive)
    {
        game.get_player().set_score(game.get_player().get_score()+diamonds_per_player);
    }
}

void treasure_card::load_texture()
{
    // TODO: Add error handling
    const std::string texture_path = "../../assets/treasure/" + std::to_string(diamonds) + ".png";
    card_texture = LoadTexture(texture_path.c_str());
}