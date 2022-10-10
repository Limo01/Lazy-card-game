#ifndef DRAWCARDSCARD_H
#define DRAWCARDSCARD_H

#include "playercardseffectcard.h"

class DrawCardsCard : public PlayerCardsEffectCard
{
public:
    /**
     * @brief DrawCardsCard => Class DrawCardsCard constructor
     * @param int => number of cards to draw (must be > 0)
     */
    DrawCardsCard(int);

    /**
     * @brief ~DrawCardsCard => Class DrawCardsCard destructor
     */
    virtual ~DrawCardsCard();

    /**
     * @brief clone
     * @return clone of the invocation object
     */
    DrawCardsCard* clone() const override;

    /**
     * @brief do_effect
     * @param players => list of players
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

#endif // DRAWCARDSCARD_H
