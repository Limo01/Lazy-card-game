#ifndef PLAYER_H
#define PLAYER_H

#include "card.h"
#include "deepptr.h"
#include "DLList.h"
#include "deck.h"
#include <string>

class Card;

class Player
{
private:
    std::string name;
    int health;
    int turnsToSkip;
    Deck<DeepPtr<Card>> deck;
    DLList<DeepPtr<Card>> hand;

public:
    /**
     * @brief Player => Class Player constructor
     * @param std::string => Player name
     * @param Deck<DeepPtr<Card>> => Cards deck
     * @param int => Player's initial life (default value = 30)
     */
    Player(const std::string&, const Deck<DeepPtr<Card>>&, int=30);

    /**
     * @brief ~Player => Class Player destructor
     */
    virtual ~Player();

    /**
     * @brief clone
     * @return clone of the invocation object
     */
    virtual Player* clone() const;

    /**
     * @brief getName
     * @return player name
     */
    std::string getName() const;

    /**
     * @brief setHealth
     * @param int => Value to which to set the life of the player
     */
    void setHealth(int);

    /**
     * @brief getHealth
     * @return life of the player
     */
    int getHealth() const;

    /**
     * @brief getHandSize
     * @return number of cards in the player's hand
     */
    int getHandSize() const;

    /**
     * @brief getHand
     * @return list of cards in the player's hand
     */
    DLList<DeepPtr<Card>>& getHand();

    /**
     * @brief getDeckSize
     * @return number of cards in the player's deck
     */
    int getDeckSize() const;

    /**
     * @brief isInGame
     * @return true if the player is still alive, false otherwise
     */
    bool isInGame() const;

    /**
     * @brief addSkipTurn => adds a turn to skip
     */
    void addSkipTurn();

    /**
     * @brief removeSkipTurn => removes a turn to be skipped
     */
    void removeSkipTurn();

    /**
     * @brief getTurnsToSkip
     * @return number of turns to skip
     */
    int getTurnsToSkip() const;

    /**
     * @brief drawCard => adds a card to the player's hand by drawing from the deck
     */
    void drawCard();

    /**
     * @brief removeCardFromHand => removes a card from the player's hand
     */
    void removeCardFromHand(int);
};

#endif // PLAYER_H
