#ifndef DRAWCARDSCARD_H
#define DRAWCARDSCARD_H

#include "playercardseffectcard.h"

class DrawCardsCard : public PlayerCardsEffectCard
{
public:
    /**
     * @brief DrawCardsCard => Costruttore della classe DrawCardsCard
     * @param int => numero di carte da pescare (deve essere > 0)
     */
    DrawCardsCard(int);

    /**
     * @brief ~DrawCardsCard => Distruttore della classe DrawCardsCard
     */
    virtual ~DrawCardsCard();

    /**
     * @brief clone
     * @return clone dell'oggetto di invocazione
     */
    DrawCardsCard* clone() const override;

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

#endif // DRAWCARDSCARD_H
