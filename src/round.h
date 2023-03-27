#pragma once

#include "danger.h"

class round
{
public:
	enum class round_state
	{
		EXPLORING,
		PLAYER_CHOICE
	};

	void add_danger(danger_type type);

private:
	round_state round_state;
	std::unordered_map<danger_type, std::uint8_t> dangers;
};