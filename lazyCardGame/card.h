#ifndef CARD_H
#define CARD_H

#include <string>
#include "DLList.h"
#include "player.h"
#include "deepptr.h"
#include <typeinfo>

class Player;

class Card
{
public:
    /**
     * @brief ~Card => Distruttore della classe Card
     */
    virtual ~Card();

    /**
     * @brief clone
     * @return clone dell'oggetto di invocazione
     */
    virtual Card* clone() const = 0;

    /**
     * @brief do_effect
     * @param players => lista dei giocatori
     * @param target => giocatore su cui applicare l'effetto della carta
     */
    virtual void do_effect(DLList<DeepPtr<Player>>& players, int target=-1) const = 0;

    /**
     * @brief getName
     * @return nome della carta
     */
    virtual std::string getName() const = 0;

    /**
     * @brief getDescription
     * @return descrizione della carta
     */
    virtual std::string getDescription() const = 0;

    /**
     * @brief operator ==
     * @param Card => carta da confrontare
     * @return true se le due carte sono uguali, false altrimenti
     */
    virtual bool operator==(const Card&) const;


    /**
     * @brief operator !=
     * @param Card => carta da confrontare
     * @return true se le due carte sono diverse, false altrimenti
     */
    virtual bool operator!=(const Card&) const;
};

#endif // CARD_H
