#pragma once

#include <vector>

class lobby
{
public:
	lobby();

	void start_game() const;
	bool is_ready() const;

	void add_user(std::string const& username);
	void kick_user(std::string const& username);

	std::uint8_t get_min_player() const;
	std::uint8_t get_max_player() const;
	std::uint8_t get_round_count() const;

	void set_min_player(std::uint8_t new_min_player);
	void set_max_player(std::uint8_t new_max_player);
	void set_round_count(std::uint8_t new_round_count);

private:
	std::uint8_t min_player, max_player;
	std::uint8_t round_count;
	std::vector<user> users;
};