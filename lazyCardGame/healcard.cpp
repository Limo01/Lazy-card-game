#include "healcard.h"

HealCard::HealCard(int h): HealthEffectCard(h){};

HealCard::~HealCard()= default;

HealCard* HealCard::clone() const
{
    return new HealCard(*this);
};

void HealCard::do_effect(DLList<DeepPtr<Player>>& players, int target) const
{
    players[target]->setHealth(players[target]->getHealth()+getHeartsNumber());
};

std::string HealCard::getName() const
{
    return "Cura " + std::to_string(getHeartsNumber());
};

std::string HealCard::getDescription() const
{
    return "Scegli un giocatore al quale aggiungere " + std::to_string(getHeartsNumber()) + " alla sua vita";
};
