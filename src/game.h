#pragma once

class game
{
public:

	std::string const& get_uuid() const;
	std::uint8_t get_current_round() const;
	std::uint8_t get_relic_found_count() const;

	void set_current_round(std::uint8_t new_round_count);
	void set_relic_found_count(std::uint8_t new_relic_found_count);

private:
	std::string uuid;
	std::uint8_t current_round;
	std::uint8_t relic_found_count;
	std::vector<round> rounds;

	void init_game();
};