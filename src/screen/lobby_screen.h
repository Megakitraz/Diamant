#pragma once

#include "core/lobby/lobby.h"
#include "screen/screen.h"

class lobby_screen : public screen
{
    public:
        lobby_screen(lobby& lobby);
        void render() override;

    private:
        lobby& lobby_;
};