#ifndef MULTIPLEATTACKCARD_H
#define MULTIPLEATTACKCARD_H

#include "healtheffectcard.h"

class MultipleAttackCard : public HealthEffectCard
{
public:
    /**
     * @brief MultipleAttackCard => Costruttore della classe MultipleAttackCard
     * @param int => numero di cuori da rimuovere dalla vita di tutti i giocatori (deve essere > 0)
     */
    MultipleAttackCard(int);

    /**
     * @brief ~MultipleAttackCard => Distruttore della classe MultipleAttackCard
     */
    virtual ~MultipleAttackCard();

    /**
     * @brief clone
     * @return clone dell'oggetto di invocazione
     */
    MultipleAttackCard* clone() const override;

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

#endif // MULTIPLEATTACKCARD_H
