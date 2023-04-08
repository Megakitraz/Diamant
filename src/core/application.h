#pragma once

#include "utils/singleton.h"
#include "scene/scene_manager.h"

class application : public singleton<application>
{
    public:
        application();
        void run();
};