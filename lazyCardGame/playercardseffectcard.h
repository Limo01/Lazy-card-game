#ifndef PLAYERCARDSEFFECTCARD_H
#define PLAYERCARDSEFFECTCARD_H

#include "card.h"

class PlayerCardsEffectCard : public Card
{
private:
    int cards_number;

public:
    /**
     * @brief PlayerHandEffectCard => Costruttore della classe PlayerHandEffectCard
     * @param int => numero di carte dell'effetto (deve essere > 0)
     */
    PlayerCardsEffectCard(int);

    /**
     * @brief ~PlayerHandEffectCard => Distruttore della classe PlayerHandEffectCard
     */
    virtual ~PlayerCardsEffectCard();

    /**
     * @brief clone
     * @return clone dell'oggetto di invocazione
     */
    virtual PlayerCardsEffectCard* clone() const override= 0;

    /**
     * @brief getCradsNumber
     * @return numero di carte dell'effetto
     */
    int getCradsNumber() const;

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

#endif // PLAYERCARDSEFFECTCARD_H
