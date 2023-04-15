#pragma once

#include "scene/scene.h"
#include "scene/scene_manager.h"
#include <memory>

class title_screen : public scene
{
    public:
        title_screen(scene_manager& scene_manager);
        void activate() override;
        void update() override;
        void render() override;
    
    private:
        scene_manager& scene_manager_;
};