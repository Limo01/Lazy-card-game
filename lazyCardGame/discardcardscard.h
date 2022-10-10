#ifndef DISCARDCARDSCARD_H
#define DISCARDCARDSCARD_H

#include "playercardseffectcard.h"

class DiscardCardsCard : public PlayerCardsEffectCard
{
public:
    /**
     * @brief DiscardCardsCard => Class DiscardCardsCard constructor
     * @param int=> number of cards to discard from a player's deck (must be > 0)
     */
    DiscardCardsCard(int);

    /**
     * @brief ~DiscardCardsCard => Class DiscardCardsCard destructor
     */
    virtual ~DiscardCardsCard();

    /**
     * @brief clone
     * @return clone of the invocation object
     */
    DiscardCardsCard* clone() const override;

    /**
     * @brief do_effect
     * @param players => list of player
     * @param target => player to apply the card effect to
     */
    void do_effect(DLList<DeepPtr<Player>>& players, int target=-1) const override;

    /**
     * @brief getName
     * @return card name
     */
    std::string getName() const override;

    /**
     * @brief getDescription
     * @return card description
     */
    std::string getDescription() const override;
};

#endif // DISCARDCARDSCARD_H
