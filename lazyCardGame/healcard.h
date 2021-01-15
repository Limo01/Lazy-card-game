#ifndef HEALCARD_H
#define HEALCARD_H

#include "healtheffectcard.h"

class HealCard : public HealthEffectCard
{
public:
    /**
     * @brief HealCard => Costruttore della classe HealCard
     * @param => int, numero di cuori da aggiugnere alla vita di un giocatore
     */
    HealCard(int);

    /**
     * @brief ~HealCard => Distruttore della classe HealCard
     */
    virtual ~HealCard();

    /**
     * @brief clone
     * @return clone dell'oggetto di invocazione
     */
    HealCard* clone() const override;

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

#endif // HEALCARD_H
