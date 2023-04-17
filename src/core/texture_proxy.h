#pragma once

#include <string>
#include <raylib.h>

namespace diamant
{
    class texture_proxy
    {
    public:
        const Texture2D load(const std::string& texture_path);
    };   
}
