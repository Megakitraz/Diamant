#pragma once

#include "utils/singleton.h"
#include "scene/scene.h"
#include "core/lobby/lobby.h"

class application : public singleton<application>
{
    public:
        application();
        void run();

    private:
        std::unique_ptr<scene> scene = nullptr;
        lobby lobby;
};