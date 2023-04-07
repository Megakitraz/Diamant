#pragma once

#include <raylib.h>

class scene
{
    public:
        virtual void update() = 0;
        virtual void render() = 0;
};