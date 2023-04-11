#pragma once

#include <raylib.h>

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

    virtual void load_texture() = 0;
    Texture2D const& get_texture() const;

protected:
    card_type type;
    Texture2D card_texture;
};

using card_type = card::card_type;