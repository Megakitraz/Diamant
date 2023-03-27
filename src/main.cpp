#include <string_view>
#include "application.h"

int main()
{
	application& app = application::get_application();
	app.run();
	return 0;
}