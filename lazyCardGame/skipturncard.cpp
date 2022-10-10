#include "skipturncard.h"

SkipTurnCard::SkipTurnCard(){};

SkipTurnCard::~SkipTurnCard()= default;

SkipTurnCard* SkipTurnCard::clone() const
{
    return new SkipTurnCard(*this);
};

void SkipTurnCard::do_effect(DLList<DeepPtr<Player>>& players, int target) const
{
    players[target]->addSkipTurn();
};

std::string SkipTurnCard::getName() const
{
    return "Skip turn";
};

std::string SkipTurnCard::getDescription() const
{
    return "Choose a player to make him skip a turn";
};
