#pragma once

#include <exception>

class no_active_scene : public std::exception
{
    public:
        const char* what() const noexcept override
        {
            return "/DIAMANT/ No active scene";
        }
};