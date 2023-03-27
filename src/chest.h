#pragma once

class chest
{
public:
	std::uint16_t get_value() const;
	void set_value(std::uint16_t new_value);

private:
	std::uint16_t value;
};