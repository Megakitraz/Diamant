#pragma once

#include "scene/scene.h"
#include "scene/scene_manager.h"
#include "utils/constants.h"

class splash_screen_scene : public scene
{
    public:
        splash_screen_scene(scene_manager& scene_manager);
        void activate() override;
        void update() override;
        void render() override;

    private:
        scene_manager& scene_manager_;

        int visible_for_ms = SPLASH_SCREEN_DURATION_MS;
        long current_time_ms = 0;
};