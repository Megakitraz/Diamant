#include "core/game.h"
#include "core/card/danger_card.h"
#include "core/card/relic_card.h"
#include "core/player/bot/strategy/easy_bot.h"
#include "core/player/bot/strategy/medium_bot.h"
#include "utils/constants.h"

#include <algorithm>
#include <ranges>
#include <assert.h>
#include <iostream>

diamant::game::game() : player("Player"), relic_found(0), round_count(5), current_round_id(0), last_played_card_index(-1)
{
    // Creating and addings bots in the game
    for(int i = 0; i<GAME_BOT_COUNT; i++)
    {
        std::string name = "Bot #" + std::to_string(i+1);
        bots.emplace_back(name, std::make_unique<diamant::medium_bot>());
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
    player.reset_score();
    for (auto& bot : bots) bot.reset_score();

    // Create new deck
    last_played_card_index = -1;
    deck.clear();
    diamant::fill_deck(deck);
    
    // Remove already played dangers
    for ( auto [danger_id, occurence] : danger_occurence)
    {
        if (occurence == 0) continue;
        deck.erase(std::remove_if(deck.begin(), deck.end(), [danger_id](const auto& card) {
            diamant::danger_card* danger = dynamic_cast<diamant::danger_card*>(card.get());
            return danger && danger->get_danger_id() == danger_id;
        }), deck.end());
    }
    danger_occurence.clear();

    // Remove found relics
    deck.erase(std::remove_if(deck.begin(), deck.end(), [this](const auto& card) {
        diamant::relic_card* relic = dynamic_cast<diamant::relic_card*>(card.get());
        return relic && relic->is_found();
    }), deck.end());

    diamant::shuffle_deck(deck);

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

int diamant::game::add_danger(int id)
{
    // operator[] will create a new entry if the key doesn't exist
    // int is initialized to 0
    return ++danger_occurence[id];
}

diamant::player& diamant::game::get_player(){ return player; }
std::vector<diamant::bot>& diamant::game::get_bots() { return bots; }
diamant::deck& diamant::game::get_deck() { return deck; }
const int diamant::game::get_relic_found() const { return relic_found; }
const int diamant::game::get_round_count() const { return round_count; }
const int diamant::game::get_current_round_id() const { return current_round_id; }