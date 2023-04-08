#pragma once

#include "scene/scene.h"
#include "utils/constants.h"

class splash_screen_scene : public scene
{
    public:
        void update() override;
        void render() override;

    private:
        int visible_for_ms = SPLASH_SCREEN_DURATION_MS;
        int current_time_ms = 0;
};