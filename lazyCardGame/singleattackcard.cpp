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
    return "Attacco singolo " + std::to_string(getHeartsNumber());
};

std::string SingleAttackCard::getDescription() const
{
    return "Scegli un giocatore a cui rimuovere " + std::to_string(getHeartsNumber()) + " cuori";
};
