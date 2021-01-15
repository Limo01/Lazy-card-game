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
     * @brief Player => Costruttore della classe Player
     * @param std::string => nome del giocatore
     * @param Deck<DeepPtr<Card>> => deck di carte
     * @param int => vita iniziale del giocatore (valore di default=30);
     */
    Player(const std::string&, const Deck<DeepPtr<Card>>&, int=30);

    /**
     * @brief ~Player => Distruttore della classe Player
     */
    virtual ~Player();

    /**
     * @brief clone
     * @return clone dell'oggetto di invocazione
     */
    virtual Player* clone() const;

    /**
     * @brief getName
     * @return nome del giocatore
     */
    std::string getName() const;

    /**
     * @brief setHealth
     * @param int => valore a cui impostare la vita del giocatore
     */
    void setHealth(int);

    /**
     * @brief getHealth
     * @return vita del giocatore
     */
    int getHealth() const;

    /**
     * @brief getHandSize
     * @return numero di carte nella mano del giocatore
     */
    int getHandSize() const;

    /**
     * @brief getHand
     * @return lista delle carte in mano al giocatore
     */
    DLList<DeepPtr<Card>>& getHand();

    /**
     * @brief getDeckSize
     * @return numero di carte nel deck del giocatore
     */
    int getDeckSize() const;

    /**
     * @brief isInGame
     * @return true se il giocatore è ancora vivo, false altrimenti
     */
    bool isInGame() const;

    /**
     * @brief addSkipTurn => aggiunge un turno da saltare
     */
    void addSkipTurn();

    /**
     * @brief removeSkipTurn => rimuove un turno da saltare
     */
    void removeSkipTurn();

    /**
     * @brief getTurnsToSkip
     * @return numero di turni da saltare
     */
    int getTurnsToSkip() const;

    /**
     * @brief drawCard => aggiunge una carta alla mano del giocatore pescando dal mazzo
     */
    void drawCard();

    /**
     * @brief removeCardFromHand => rimuove una carta dalla mano del giocatore
     */
    void removeCardFromHand(int);
};

#endif // PLAYER_H
