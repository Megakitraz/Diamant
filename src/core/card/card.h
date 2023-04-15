#pragma once

#include <raylib.h>

namespace diamant {

    class card {

    public:

        card();
        virtual ~card();

        bool is_played() const;
        Texture2D const& get_texture() const;

        virtual void load_texture() = 0;
        virtual void play();

    protected:
        Texture2D card_texture;
        bool played;
    };

}
