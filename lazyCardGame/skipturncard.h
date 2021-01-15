#ifndef SKIPTURNCARD_H
#define SKIPTURNCARD_H

#include "card.h"

class SkipTurnCard : public Card
{
public:
    /**
     * @brief SkipTurnCard => Costruttore della classe SkipTurnCard
     */
    SkipTurnCard();

    /**
     * @brief ~SkipTurnCard => Distruttore della classe SkipTurnCard
     */
    virtual ~SkipTurnCard();

    /**
     * @brief clone
     * @return clone dell'oggetto di invocazione
     */
    SkipTurnCard* clone() const override;

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

#endif // SKIPTURNCARD_H
