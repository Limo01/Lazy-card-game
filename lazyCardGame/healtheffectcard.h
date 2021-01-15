#ifndef HEALTHEFFECTCARD_H
#define HEALTHEFFECTCARD_H

#include "card.h"

class HealthEffectCard : public Card
{
private:
    int hearts_number;

public:
    /**
     * @brief HealthEffectCard => Costruttore della classe HealthEffectCard
     * @param int => numero di cuori dell'effetto (deve essere > 0)
     */
    HealthEffectCard(int);

    /**
     * @brief ~HealthEffectCard => Distruttore della classe HealthEffectCard
     */
    virtual ~HealthEffectCard();

    /**
     * @brief clone
     * @return clone dell'oggetto di invocazione
     */
    virtual Card* clone() const override= 0;

    /**
     * @brief getHeartsNumber
     * @return numero di cuori dell'effetto
     */
    int getHeartsNumber() const;

    /**
     * @brief operator ==
     * @param Card => carta da confrontare
     * @return true se le due carte sono uguali, false altrimenti
     */
    virtual bool operator==(const Card&) const override;

    /**
     * @brief operator !=
     * @param Card => carta da confrontare
     * @return true se le due carte sono diverse, false altrimenti
     */
    virtual bool operator!=(const Card&) const override;
};

#endif // HEALTHEFFECTCARD_H
