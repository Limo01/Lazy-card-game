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
     * @brief ~Card => Class Card destructor
     */
    virtual ~Card();

    /**
     * @brief clone
     * @return clone of the invocation object
     */
    virtual Card* clone() const = 0;

    /**
     * @brief do_effect
     * @param players => players list
     * @param target => player to apply the card effect to
     */
    virtual void do_effect(DLList<DeepPtr<Player>>& players, int target=-1) const = 0;

    /**
     * @brief getName
     * @return card name
     */
    virtual std::string getName() const = 0;

    /**
     * @brief getDescription
     * @return card description
     */
    virtual std::string getDescription() const = 0;

    /**
     * @brief operator ==
     * @param Card => card to compare
     * @return true if the cards are equals, false otherwise
     */
    virtual bool operator==(const Card&) const;


    /**
     * @brief operator !=
     * @param Card => card to compare
     * @return true if the cards are different, false otherwise
     */
    virtual bool operator!=(const Card&) const;
};

#endif // CARD_H
