#pragma once

#include "scene/scene.h"
#include "scene/scene_manager.h"
#include "core/game.h"
#include <memory>

class game_scene : public scene
{
    public:
        game_scene(scene_manager& scene_manager);
        void activate() override;
        void update() override;
        void render() override;

    private:
        scene_manager& scene_manager_;
        
        long current_time_ms = 0;
        std::unique_ptr<diamant::game> game = nullptr;
};