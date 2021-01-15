#include "playercardseffectcard.h"

PlayerCardsEffectCard::PlayerCardsEffectCard(int c): cards_number(c)
{
    if(c<=0)
        throw std::domain_error("PlayerCardsEffectCard::PlayerCardsEffectCard(int): parameter int must be >= 0");
};

PlayerCardsEffectCard::~PlayerCardsEffectCard()= default;

int PlayerCardsEffectCard::getCradsNumber() const
{
    return cards_number;
};

bool PlayerCardsEffectCard::operator==(const Card& c) const
{
    return Card::operator==(c) && static_cast<const PlayerCardsEffectCard&>(c).getCradsNumber()==getCradsNumber();
};

bool PlayerCardsEffectCard::operator!=(const Card& c) const
{
    return Card::operator!=(c) && static_cast<const PlayerCardsEffectCard&>(c).getCradsNumber()!=getCradsNumber();
};
