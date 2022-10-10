#ifndef CARDCREATOR_H
#define CARDCREATOR_H

#include <ctime>
#include "deepptr.h"
#include "card.h"
#include "deck.h"
#include "singleattackcard.h"
#include "multipleattackcard.h"
#include "healcard.h"
#include "skipturncard.h"
#include "drawcardscard.h"
#include "discardcardscard.h"

class CardCreator
{
public:
    /**
     * @brief CardCreator => Class CardCreator constructor
     */
    CardCreator();

    /**
     * @brief ~CardCreator => Class CardCreator destructor
     */
    ~CardCreator();

    /**
     * @brief createSingleAttackCard
     * @return SingleAttackCard type card
     */
    DeepPtr<Card> createSingleAttackCard(int=0) const;

    /**
     * @brief createMultipleAttackCard
     * @return MultipleAttackCard type card
     */
    DeepPtr<Card> createMultipleAttackCard(int=0) const;

    /**
     * @brief createHealCard
     * @return HealCard type card
     */
    DeepPtr<Card> createHealCard(int=0) const;

    /**
     * @brief createSkipTurnCard
     * @return SkipTurnCard type card
     */
    DeepPtr<Card> createSkipTurnCard() const;

    /**
     * @brief createDrawCardsCard
     * @return DrawCardsCard type card
     */
    DeepPtr<Card> createDrawCardsCard(int=0) const;

    /**
     * @brief createDiscardCardsCard
     * @return DiscardCardsCard type card
     */
    DeepPtr<Card> createDiscardCardsCard(int=0) const;

    /**
     * @brief createRandomCard
     * @return random type card
     */
    DeepPtr<Card> createRandomCard() const;

    /**
     * @brief createRandomDeck
     * @param int => number of cards in the deck
     * @return random deck of cards
     */
    Deck<DeepPtr<Card>> createRandomDeck(int=52) const;
};

#endif // CARDCREATOR_H
