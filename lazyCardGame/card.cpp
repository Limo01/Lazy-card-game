#include "card.h"

Card::~Card()= default;

bool Card::operator==(const Card& c) const
{
    return typeid(*this) == typeid(c);
};

bool Card::operator!=(const Card& c) const
{
    return typeid(*this) != typeid(c);
};
