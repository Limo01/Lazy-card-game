#ifndef HEALCARD_H
#define HEALCARD_H

#include "healtheffectcard.h"

class HealCard : public HealthEffectCard
{
public:
    /**
     * @brief HealCard => Classe HealCard constructor
     * @param => int, number of hearts to add to a player's life
     */
    HealCard(int);

    /**
     * @brief ~HealCard => Class HealCard destructor
     */
    virtual ~HealCard();

    /**
     * @brief clone
     * @return clone of the invocation object
     */
    HealCard* clone() const override;

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

#endif // HEALCARD_H
