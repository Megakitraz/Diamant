#pragma once

#include "utils/singleton.h"
#include "screen/screen.h"
#include "core/lobby/lobby.h"

class application : public singleton<application>
{
    public:
        application();
        void run();

    private:
        std::unique_ptr<screen> screen = nullptr;
        lobby lobby;
};