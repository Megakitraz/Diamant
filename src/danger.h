#pragma once

class danger : public card
{
public:
	enum class danger_type
	{
		GIANT_SPIDER,
		LAVA_PIT,
		STONE_BALL,
		WOODEN_RAM,
		SNAKE
	};

	danger_type get_danger_type() const;

private:
	danger_type danger_type;
};