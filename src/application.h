#pragma once

#include <string_view>

constexpr std::string_view TITLE = "Diamant";
constexpr std::uint16_t WINDOW_WIDTH = 800;
constexpr std::uint16_t WINDOW_HEIGHT = 400;

class application
{
public:
	static application& get_application();

	void run();

private:
	std::string_view title;
	std::uint16_t window_width, window_height;

	application(std::string_view title, std::uint16_t window_width, std::uint16_t window_height);
	application(application const& other) = delete;
	application& operator=(application const& other) = delete;
};