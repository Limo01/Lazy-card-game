#ifndef MULTIPLEATTACKCARD_H
#define MULTIPLEATTACKCARD_H

#include "healtheffectcard.h"

class MultipleAttackCard : public HealthEffectCard
{
public:
    /**
     * @brief MultipleAttackCard => Class MultipleAttackCard constructor
     * @param int => number of hearts to be removed from the life of all players (must be > 0)
     */
    MultipleAttackCard(int);

    /**
     * @brief ~MultipleAttackCard => Class MultipleAttackCard destructor
     */
    virtual ~MultipleAttackCard();

    /**
     * @brief clone
     * @return clone of the invocation object
     */
    MultipleAttackCard* clone() const override;

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

#endif // MULTIPLEATTACKCARD_H
