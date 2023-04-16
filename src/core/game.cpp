#include "core/game.h"
#include "utils/constants.h"
#include <algorithm>
#include <ranges>
#include <assert.h>
#include <iostream>

diamant::game::game() : player("Player"), round_count(5), current_round_id(0), last_played_card_index(-1)
{
    // Creating and addings bots in the game
    const float moving_forward_probability = 1.f;
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
    current_round_id++;

    player.set_status(PlayerStatus::WaitingForNextMove);
    for (auto& bot : bots) bot.set_status(PlayerStatus::WaitingForIsTurn); 

    new_turn();
}

void diamant::game::new_turn()
{
    // Update status
    if (player.get_status() != PlayerStatus::Inactive)
        player.set_status(PlayerStatus::WaitingForNextMove);

    // Reset last action of all players
    player.set_last_action(PlayerAction::None);
    for (auto& bot : bots) bot.set_last_action(PlayerAction::None);
    
    // Pick new card
    const bool is_deck_empty = deck.empty();
    assert( !is_deck_empty && "Deck is empty." );
    auto card = deck[++last_played_card_index].get();
    card->on_pick();
}

void diamant::game::end_round()
{
    // Reset expedition score
    player.set_score(0);
    for (auto& bot : bots) bot.set_score(0);

    for (auto& card : deck)
        card->set_played(false);
    diamant::shuffle_deck(deck);
    last_played_card_index = -1;

    new_round();
}

void diamant::game::end_turn()
{
    // Backwards from the cards
    // verifier si joueur ou bot leave
    for (auto& card : std::ranges::reverse_view(deck))
    {
        if (!card->is_played()) continue;
        card->on_left();
    }

    // Save score
    if (player.get_last_action() == PlayerAction::Leave)
        player.get_chest().add(player.get_score());
    for (auto& bot : bots)
    {
        if (bot.get_last_action() == PlayerAction::Leave)
            bot.get_chest().add(bot.get_score());
    }

    // Wait and go to next turn or round
    //WaitTime(GAME_TURN_WAIT);
    const int active_players = get_active_players();
    if( active_players == 0)
        end_round();
    else
        new_turn();
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

std::vector<diamant::player*> diamant::game::get_gone_players()
{
    std::vector<diamant::player*> gone_players;
    if (player.get_last_action() == PlayerAction::Leave) 
        gone_players.push_back(&player);
    for (auto& bot : bots)
        if (bot.get_last_action() == PlayerAction::Leave) 
            gone_players.push_back(&bot);
    return gone_players;
}

diamant::player& diamant::game::get_player(){ return player; }
std::vector<diamant::bot>& diamant::game::get_bots() { return bots; }
diamant::deck& diamant::game::get_deck() { return deck; }
int diamant::game::get_round_count() const { return round_count; }
int diamant::game::get_current_round_id() const { return current_round_id; }