#include "core/card/relic_card.h"
#include "core/game.h"
#include <iostream>

diamant::relic_card::relic_card() : found(false)
{
    load_texture();
}

void diamant::relic_card::on_left() 
{
    if (found) return;

    diamant::game& game = diamant::game::instance();
    std::vector<diamant::player*> gone_player = game.get_gone_players();
    if (gone_player.size() != 1) return;

    const int relic_found = game.get_relic_found();
    const int increment = relic_found > 3 ? 10 : 5;
    gone_player.front()->add_score(increment);
    found = true;
}

void diamant::relic_card::load_texture()
{
    // TODO: Add error handling
    const std::string texture_path = "relic.png";
    card_texture = proxy.load(texture_path);
}

bool diamant::relic_card::is_found() const { return found; }