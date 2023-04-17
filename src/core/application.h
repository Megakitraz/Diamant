#pragma once

#include "utils/singleton.h"
#include "scenes/scene_manager.h"

class application : public singleton<application>
{
    public:
        application();
        void run();

    private:
        scene_manager scene_manager_;
};