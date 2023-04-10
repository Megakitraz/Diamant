#include "utils/time.h"
#include <sstream>
#include <iomanip>

std::string time_to_string(long time_ms)
{
    const int seconds = (time_ms / 1000 ) % 60;
    const int minutes = (seconds / 60) % 60;
    const int hours = (minutes / 60) % 24;
    std::stringstream ss;
    ss  << std::setfill('0') << std::setw(2) << hours << ":" 
        << std::setw(2) << minutes << ":" 
        << std::setw(2) << seconds;
    return ss.str();
}