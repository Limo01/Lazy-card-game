#ifndef PLAYERCARDSEFFECTCARD_H
#define PLAYERCARDSEFFECTCARD_H

#include "card.h"

class PlayerCardsEffectCard : public Card
{
private:
    int cards_number;

public:
    /**
     * @brief PlayerHandEffectCard => Class PlayerHandEffectCard constructor
     * @param int => Number of cards in the effect (must be> 0)
     */
    PlayerCardsEffectCard(int);

    /**
     * @brief ~PlayerHandEffectCard => Class PlayerHandEffectCard destructor
     */
    virtual ~PlayerCardsEffectCard();

    /**
     * @brief clone
     * @return clone of the invocation object
     */
    virtual PlayerCardsEffectCard* clone() const override= 0;

    /**
     * @brief getCradsNumber
     * @return number of cards of the effect
     */
    int getCradsNumber() const;

    /**
     * @brief operator ==
     * @param Card => Card to compare
     * @return true if the two cards are equal, false otherwise
     */
    virtual bool operator==(const Card&) const override;

    /**
     * @brief operator !=
     * @param Card => Card to compare
     * @return true if the two cards are different, false otherwise
     */
    virtual bool operator!=(const Card&) const override;
};

#endif // PLAYERCARDSEFFECTCARD_H
