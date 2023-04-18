#include "core/card/danger_card.h"
#include "core/game.h"
#include <iostream>

diamant::danger_card::danger_card(int danger_id) : danger_id(danger_id)
{
    load_texture();
}

const int diamant::danger_card::get_danger_id() const { return danger_id; }

void diamant::danger_card::on_pick()
{
    diamant::card::on_pick();
    diamant::game& game = diamant::game::instance();
    const int occurence = game.add_danger(danger_id);
    if (occurence > 1)
        game.set_round_finished(true);
}

void diamant::danger_card::on_left() {}

void diamant::danger_card::load_texture()
{
    const std::string texture_path = "danger/" + std::to_string(danger_id) + ".png";
    try
    {
        card_texture = proxy.load(texture_path);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        std::exit(EXIT_FAILURE);
    }
}