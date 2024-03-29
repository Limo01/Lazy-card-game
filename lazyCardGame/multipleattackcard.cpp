#include "multipleattackcard.h"

MultipleAttackCard::MultipleAttackCard(int h): HealthEffectCard(h){};

MultipleAttackCard::~MultipleAttackCard()= default;

MultipleAttackCard* MultipleAttackCard::clone() const
{
    return new MultipleAttackCard(*this);
};

void MultipleAttackCard::do_effect(DLList<DeepPtr<Player>>& players, int) const
{
    for(int i=0; i<players.getSize(); i++)
    {
        players[i]->setHealth(players[i]->getHealth()-getHeartsNumber());
    }
};

std::string MultipleAttackCard::getName() const
{
    return "Multiple attack " + std::to_string(getHeartsNumber());
};

std::string MultipleAttackCard::getDescription() const
{
    return "Remove " + std::to_string(getHeartsNumber()) + " hearts to all players";
};
