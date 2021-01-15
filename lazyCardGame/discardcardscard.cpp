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
    return "Scarta " + std::to_string(getCradsNumber());
};

std::string DiscardCardsCard::getDescription() const
{
    return "Scegli un giocatore al quale far scartare " + std::to_string(getCradsNumber()) + " carte dal proprio mazzo";
};
