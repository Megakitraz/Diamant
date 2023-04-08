#pragma once

#include "scene/scene.h"

class lobby_scene : public scene
{
    public:
        void update() override;
        void render() override;
};