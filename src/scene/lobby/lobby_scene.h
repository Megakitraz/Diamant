#pragma once

#include <core/lobby.h>
#include "scene/scene.h"

class lobby_scene : public scene
{
    public:
        void update() override;
        void render() override;
    
    private:
        lobby lobby_;
};