#include "discardcardscard.h"

DiscardCardsCard::DiscardCardsCard(int c):PlayerCardsEffectCard(c){};

DiscardCardsCard::~DiscardCardsCard()= default;

DiscardCardsCard* DiscardCardsCard::clone() const
{
    return new DiscardCardsCard(*this);
};

void DiscardCardsCard::do_effect(DLList<DeepPtr<Player>>& players, int target) const
{
    for(int i=0; i<getCradsNumber(); i++)
    {
        players[target]->drawCard();

        if(players[target]->getHandSize()>0)
            players[target]->getHand().removeBack();
    }
};

std::string DiscardCardsCard::getName() const
{
    return "Discard " + std::to_string(getCradsNumber());
};

std::string DiscardCardsCard::getDescription() const
{
    return "Choose a player to make him discard " + std::to_string(getCradsNumber()) + "cards from his deck";
};
