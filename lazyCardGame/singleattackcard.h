#ifndef SINGLEATTACKCARD_H
#define SINGLEATTACKCARD_H

#include "healtheffectcard.h"

class SingleAttackCard : public HealthEffectCard
{
public:
    /**
     * @brief SingleAttackCard => Class SingleAttackCard constructor
     * @param int => Number of hearts to be removed from a player's life (must be> 0)
     */
    SingleAttackCard(int);

    /**
     * @brief ~SingleAttackCard => Class SingleAttackCard destructor
     */
    virtual ~SingleAttackCard();

    /**
     * @brief clone
     * @return clone of the invocation object
     */
    SingleAttackCard* clone() const override;

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

#endif // SINGLEATTACKCARD_H
