#ifndef SINGLEATTACKCARD_H
#define SINGLEATTACKCARD_H

#include "healtheffectcard.h"

class SingleAttackCard : public HealthEffectCard
{
public:
    /**
     * @brief SingleAttackCard => Costruttore della classe SingleAttackCard
     * @param int => numero di cuori da rimuovere dalla vita di un giocatore (deve essere > 0)
     */
    SingleAttackCard(int);

    /**
     * @brief ~SingleAttackCard => Distruttore della classe SingleAttackCard
     */
    virtual ~SingleAttackCard();

    /**
     * @brief clone
     * @return clone dell'oggetto di invocazione
     */
    SingleAttackCard* clone() const override;

    /**
     * @brief do_effect
     * @param players => lista dei giocatori
     * @param target => giocatore su cui applicare l'effetto della carta
     */
    void do_effect(DLList<DeepPtr<Player>>& players, int target=-1) const override;

    /**
     * @brief getName
     * @return nome della carta
     */
    std::string getName() const override;

    /**
     * @brief getDescription
     * @return descrizione della carta
     */
    std::string getDescription() const override;
};

#endif // SINGLEATTACKCARD_H
