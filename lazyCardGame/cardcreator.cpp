#include "cardcreator.h"

CardCreator::CardCreator()
{
    srand(time(NULL));
};

CardCreator::~CardCreator()= default;

DeepPtr<Card> CardCreator::createSingleAttackCard(int v) const
{
    return DeepPtr<Card>(new SingleAttackCard(v==0? rand()%8+3 : v));
};

DeepPtr<Card> CardCreator::createMultipleAttackCard(int v) const
{
    return DeepPtr<Card>(new MultipleAttackCard(v==0? rand()%3+3 : v));
};

DeepPtr<Card> CardCreator::createHealCard(int v) const
{
    return DeepPtr<Card>(new HealCard(v==0? rand()%8+3 : v));
};

DeepPtr<Card> CardCreator::createSkipTurnCard() const
{
    return DeepPtr<Card>(new SkipTurnCard());
};

DeepPtr<Card> CardCreator::createDrawCardsCard(int v) const
{
    return DeepPtr<Card>(new DrawCardsCard(v==0? rand()%4+2 : v));
};

DeepPtr<Card> CardCreator::createDiscardCardsCard(int v) const
{
    return DeepPtr<Card>(new DiscardCardsCard(v==0? rand()%4+2 : v));
};

DeepPtr<Card> CardCreator::createRandomCard() const
{
    int random= rand()%6;

    switch(random)
    {
    case 0:
        return createSingleAttackCard();
    case 1:
        return createMultipleAttackCard();
    case 2:
        return createHealCard();
    case 3:
        return createDiscardCardsCard();
    case 4:
        return createSkipTurnCard();
    }
    return createDrawCardsCard();
};

Deck<DeepPtr<Card>> CardCreator::createRandomDeck(int n) const
{
    Deck<DeepPtr<Card>> d(n);

    for(int i=0; i<n; i++)
        d.push_top(createRandomCard());

    return d;
};
