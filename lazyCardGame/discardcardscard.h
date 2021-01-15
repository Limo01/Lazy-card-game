#ifndef DISCARDCARDSCARD_H
#define DISCARDCARDSCARD_H

#include "playercardseffectcard.h"

class DiscardCardsCard : public PlayerCardsEffectCard
{
public:
    /**
     * @brief DiscardCardsCard => Costruttore della classe DiscardCardsCard
     * @param int=> numero di carte da scartare dal deck di un giocatore (deve essere > 0)
     */
    DiscardCardsCard(int);

    /**
     * @brief ~DiscardCardsCard => Distruttore della classe DiscardCardsCard
     */
    virtual ~DiscardCardsCard();

    /**
     * @brief clone
     * @return clone dell'oggetto di invocazione
     */
    DiscardCardsCard* clone() const override;

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

#endif // DISCARDCARDSCARD_H
