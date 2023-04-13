#pragma once

#include <raylib.h>

namespace diamant {

    class card {

    public:

        enum class card_type
        {
            Treasure,
            Danger,
            Relic
        };

        card(card_type type);
        virtual ~card();

        card_type get_type() const;
        bool is_played() const;
        Texture2D const& get_texture() const;

        void set_played(bool played);

        virtual void load_texture() = 0;

    protected:
        card_type type;
        Texture2D card_texture;
        bool played;
    };

    using card_type = card::card_type;

}
