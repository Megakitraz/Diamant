#include "core/game.h"
#include "utils/constants.h"
#include <algorithm>
#include <assert.h>

diamant::game::game() : player("Player"), round_count(5), last_played_card_index(-1)
{
    // Creating and addings bots in the game
    const float moving_forward_probability = 0.8f;
    for(int i = 0; i<GAME_BOT_COUNT; i++)
    {
        std::string name = "Bot #" + std::to_string(i+1);
        bots.emplace_back(name, moving_forward_probability);
    }
    
    // Filling the deck with cards (treasure, danger, relic)
    diamant::fill_deck(deck);
    diamant::shuffle_deck(deck);
}

void diamant::game::new_round()
{
    player.set_status(PlayerStatus::WaitingForNextMove);
    for (auto& bot : bots)
        bot.set_status(PlayerStatus::WaitingForIsTurn);

    new_turn();
}

void diamant::game::new_turn()
{
    pick_card();
}

void diamant::game::pick_card()
{
    const bool is_deck_empty = deck.empty();
    assert( !is_deck_empty && "Deck is empty." );
    auto card = deck[++last_played_card_index].get();
    card->play();
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
diamant::deck& diamant::game::get_deck() { return deck; }
int diamant::game::get_round_count() const { return round_count; }
int diamant::game::get_current_round_id() const { return current_round_id; }