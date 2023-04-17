#pragma once

#include "core/player/player.h"
#include "core/texture_proxy.h"
#include <raylib.h>
#include <vector>

namespace diamant {

    class card {

    public:

        card();
        virtual ~card();

        void set_played(bool played);
        bool is_played() const;
        Texture2D const& get_texture() const;

        virtual void load_texture() = 0;
        virtual void on_pick();
        virtual void on_left() = 0;

    protected:
        Texture2D card_texture;
        diamant::texture_proxy proxy;
        bool played;
    };

}
