#pragma once

#include "scenes/scene.h"
#include "scenes/scene_manager.h"
#include "core/game.h"
#include "utils/constants.h"
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
        double sleed_for_sec = GAME_TURN_WAIT;
};