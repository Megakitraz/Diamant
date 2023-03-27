#pragma once

#include <vector>

class user
{
public:
	user();

	void add_friend(std::string const& username);
	void remove_friend(std::string const& username);

	bool is_playing() const;
	void set_state(bool playing);

	std::string const& get_uuid() const;
	std::string const& get_username() const;

private:
	std::string uuid;
	std::string username;
	bool in_game;
	std::vector<user> friends;
};