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
     * @brief CardCreator => Costruttore della classe CardCreator
     */
    CardCreator();

    /**
     * @brief ~CardCreator => Distruttore della classe CardCreator
     */
    ~CardCreator();

    /**
     * @brief createSingleAttackCard
     * @return carta di tipo SingleAttackCard
     */
    DeepPtr<Card> createSingleAttackCard(int=0) const;

    /**
     * @brief createMultipleAttackCard
     * @return carta di tipo MultipleAttackCard
     */
    DeepPtr<Card> createMultipleAttackCard(int=0) const;

    /**
     * @brief createHealCard
     * @return carta di tipo HealCard
     */
    DeepPtr<Card> createHealCard(int=0) const;

    /**
     * @brief createSkipTurnCard
     * @return carta di tipo SkipTurnCard
     */
    DeepPtr<Card> createSkipTurnCard() const;

    /**
     * @brief createDrawCardsCard
     * @return carta di tipo DrawCardsCard
     */
    DeepPtr<Card> createDrawCardsCard(int=0) const;

    /**
     * @brief createDiscardCardsCard
     * @return carta di tipo DiscardCardsCard
     */
    DeepPtr<Card> createDiscardCardsCard(int=0) const;

    /**
     * @brief createRandomCard
     * @return carta di tipo random
     */
    DeepPtr<Card> createRandomCard() const;

    /**
     * @brief createRandomDeck
     * @param int => numero di carte del mazzo
     * @return mazzo di carte random
     */
    Deck<DeepPtr<Card>> createRandomDeck(int=52) const;
};

#endif // CARDCREATOR_H
