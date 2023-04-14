#include "core/game.h"
#include "utils/constants.h"

diamant::game::game() : round_count(5) 
{
    const float moving_forward_probability = 0.8f;
    for(int i = 0; i<GAME_BOT_COUNT; i++)
        bots.emplace_back(moving_forward_probability);
}

void diamant::game::start()
{
    round.create_deck();
    round.pick_card();
    player.set_status(PlayerStatus::WaitingForNextMove);
    for (auto& bot : bots)
        bot.set_status(PlayerStatus::WaitingForIsTurn);
}

void diamant::game::next_round()
{
    //round next(round_.id + 1);
    //next_round.deck = create_deck().shuffle();
    //round_ = std::move(next);
}

diamant::player& diamant::game::get_player(){ return player; }
std::vector<diamant::bot>& diamant::game::get_bots() { return bots; }
diamant::round& diamant::game::get_round() { return round; }

int diamant::game::get_round_count() const { return round_count; }