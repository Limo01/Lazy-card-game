#include "drawcardscard.h"

DrawCardsCard::DrawCardsCard(int c): PlayerCardsEffectCard(c){};

DrawCardsCard::~DrawCardsCard()= default;

DrawCardsCard* DrawCardsCard::clone() const
{
    return new DrawCardsCard(*this);
};

void DrawCardsCard::do_effect(DLList<DeepPtr<Player>>& players, int target) const
{
    for(int i=0; i<getCradsNumber(); i++)
        players[target]->drawCard();
};

std::string DrawCardsCard::getName() const
{
    return "Pesca " + std::to_string(getCradsNumber());
};

std::string DrawCardsCard::getDescription() const
{
    return "Scegli un giocatore al quale far pescare " + std::to_string(getCradsNumber()) + " carte";
};
