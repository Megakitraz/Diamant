#pragma once

#include <vector>
#include "player.h"

class treasure : public card
{
public:

	void collect(std::vector<player> players);

private:
	std::uint8_t diamonds;
};