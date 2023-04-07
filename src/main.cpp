#include "core/application.h"

int main()
{
	application& app = application::instance();
	app.run();
	return 0;
}