#ifndef SKIPTURNCARD_H
#define SKIPTURNCARD_H

#include "card.h"

class SkipTurnCard : public Card
{
public:
    /**
     * @brief SkipTurnCard => Class SkipTurnCard constructor
     */
    SkipTurnCard();

    /**
     * @brief ~SkipTurnCard => Class SkipTurnCard destructor
     */
    virtual ~SkipTurnCard();

    /**
     * @brief clone
     * @return clone of the invocation object
     */
    SkipTurnCard* clone() const override;

    /**
     * @brief do_effect
     * @param players => Players list
     * @param target => Player to apply the card effect to
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

#endif // SKIPTURNCARD_H
