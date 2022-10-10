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
    return "Heal " + std::to_string(getHeartsNumber());
};

std::string HealCard::getDescription() const
{
    return "Choose a player to add " + std::to_string(getHeartsNumber()) + " hearts to his life";
};
