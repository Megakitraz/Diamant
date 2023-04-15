#include "core/chest.h"

diamant::chest::chest()
    : diamonds(0)
{}

void diamant::chest::add(int diamonds) { this->diamonds += diamonds; }
void diamant::chest::clear() { diamonds = 0; }