#include "singleattackcard.h"

SingleAttackCard::SingleAttackCard(int h): HealthEffectCard(h){};

SingleAttackCard::~SingleAttackCard()= default;

SingleAttackCard* SingleAttackCard::clone() const
{
    return new SingleAttackCard(*this);
};

void SingleAttackCard::do_effect(DLList<DeepPtr<Player>>& players, int target) const
{
    players[target]->setHealth(players[target]->getHealth()-getHeartsNumber());
};

std::string SingleAttackCard::getName() const
{
    return "Single attack " + std::to_string(getHeartsNumber());
};

std::string SingleAttackCard::getDescription() const
{
    return "Choose a player to remove from " + std::to_string(getHeartsNumber()) + " hearts";
};
