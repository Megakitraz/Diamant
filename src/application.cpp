#include "application.h"

application::application(std::string_view title, std::uint16_t window_width, std::uint16_t window_height) :
	title(title),
	window_width(window_width),
	window_height(window_height)
{}

application& application::get_application()
{
	static application instance(TITLE, WINDOW_WIDTH, WINDOW_HEIGHT);
	return instance;
}

void application::run()
{

}