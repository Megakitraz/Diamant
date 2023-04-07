#pragma once

#include "core/lobby/lobby.h"
#include "scene/scene.h"

class lobby_scene : public scene
{
    public:
        lobby_scene(lobby& lobby);

        void update() override;
        void render() override;

    private:
        lobby& lobby_;
};