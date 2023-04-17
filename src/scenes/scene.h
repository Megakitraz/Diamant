#pragma once

#include <raylib.h>

class scene
{
    public:
        virtual void activate() = 0;
        virtual void update() = 0;
        virtual void render() = 0;
};