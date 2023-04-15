#include "core/game.h"
#include "utils/constants.h"
#include <algorithm>

diamant::game::game() : round_count(5) 
{
    const float moving_forward_probability = 0.8f;
    for(int i = 0; i<GAME_BOT_COUNT; i++)
        bots.emplace_back(moving_forward_probability);
}

void diamant::game::start()
{
    round.create_deck();
    player.set_status(PlayerStatus::WaitingForNextMove);
    for (auto& bot : bots)
        bot.set_status(PlayerStatus::WaitingForIsTurn);
    round.pick_card();
}

void diamant::game::next_round()
{
    //round next(round_.id + 1);
    //next_round.deck = create_deck().shuffle();
    //round_ = std::move(next);
}

int diamant::game::get_active_players() const 
{ 
    int active_players = 0;
    const auto is_active = [](const auto& player) -> bool { return player.get_status() != PlayerStatus::Inactive; };
    active_players += is_active(player);
    for (const auto& bot: bots)
        active_players += is_active(bot);
    return active_players;
}

diamant::player& diamant::game::get_player(){ return player; }
std::vector<diamant::bot>& diamant::game::get_bots() { return bots; }
diamant::round& diamant::game::get_round() { return round; }

int diamant::game::get_round_count() const { return round_count; }