#ifndef HEALTHEFFECTCARD_H
#define HEALTHEFFECTCARD_H

#include "card.h"

class HealthEffectCard : public Card
{
private:
    int hearts_number;

public:
    /**
     * @brief HealthEffectCard => Class HealthEffectCard contructor
     * @param int => number of hearts in the effect (must be> 0)
     */
    HealthEffectCard(int);

    /**
     * @brief ~HealthEffectCard => Class HealthEffectCard destructor
     */
    virtual ~HealthEffectCard();

    /**
     * @brief clone
     * @return clone of the invocation object
     */
    virtual Card* clone() const override= 0;

    /**
     * @brief getHeartsNumber
     * @return number of hearts of the effect
     */
    int getHeartsNumber() const;

    /**
     * @brief operator ==
     * @param Card => card to compare
     * @return true if the two cards are equal, false otherwise
     */
    virtual bool operator==(const Card&) const override;

    /**
     * @brief operator !=
     * @param Card => card to compare
     * @return true if the two cards are different, false otherwise
     */
    virtual bool operator!=(const Card&) const override;
};

#endif // HEALTHEFFECTCARD_H
