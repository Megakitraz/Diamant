#pragma once

#include <core/lobby.h>
#include "scene/scene.h"
#include "scene/scene_manager.h"

class lobby_scene : public scene
{
    public:
        lobby_scene(scene_manager& scene_manager);
        void update() override;
        void render() override;
    
    private:
        scene_manager& scene_manager_;

        lobby lobby_;
};