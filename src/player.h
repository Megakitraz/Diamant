#pragma once

#include "user.h"
#include "chest.h"

class player : public user;
{
public:
	void choice_action() const;

	bool is_exploring() const;
	void set_exploration_state(bool exploring);

private:
	std::uint16_t score_expedition;
	bool in_exploration;
	chest chest;
};