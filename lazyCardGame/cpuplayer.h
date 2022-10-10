#ifndef CPUPLAYER_H
#define CPUPLAYER_H

#include "player.h"
#include <string>
#include <ctime>
#include "healcard.h"
#include "singleattackcard.h"
#include "multipleattackcard.h"
#include "discardcardscard.h"

class CpuPlayer : public Player
{
private:
    /**
     * @brief findThisTarget => Function to find the index of the player that is calling the function within the players list
     * @param players => DLList<DeepPtr<Player>>, list of players passed by reference
     * @param targetPlayer => int, variable passed by reference that will contain the player's index
     */
    void findThisTarget(DLList<DeepPtr<Player>>& players, int& targetPlayer) const;

    /**
     * @brief searchHealCard => Function to search for the health card with the highest value in the hand
     * @param targetCard => int, variable passed by reference that will contain the index of the card inside the player's hand (if found, otherwise it will contain the initial value)
     */
    void searchHealCard(int& targetCard);

    /**
     * @brief searchPossibleKill => Function to see if it is possible to kill one of the players using a given attack value
     * @param players => DLList<DeepPtr<Player>>, list of players passed by reference
     * @param targetPlayer => int, variable passed by reference that will contain the index of the selected player (if found, otherwise it will contain the initial value)
     * @param attackValue => int, attack value of the card we want to use
     */
    void searchPossibleKill(DLList<DeepPtr<Player>>& players, int& targetPlayer, int attackValue) const;

    /**
     * @brief searchPossibleAttack => Function to search if it is possible to launch a fatal attack on a player
     * @param players => DLList<DeepPtr<Player>>, list of players passed by reference
     * @param targetCard => int, variable passed by reference that will contain the index of the attack card inside the player's hand (only if he has found a possible attack, otherwise it will contain the initial value)
     * @param targetPlayer => int, variable passed by reference that will contain the index of the selected player (only if it has found a possible attack, otherwise it will contain the initial value)
     */
    void searchPossibleAttack(DLList<DeepPtr<Player>>& players, int& targetCard, int& targetPlayer);

public:
    /**
     * @brief CpuPlayer => Classe CpuPlayer constructor
     * @param std::string => player name
     * @param Deck<DeepPtr<Card>> => deck of cards
     * @param int => player's initial life (default = 30)
     */
    CpuPlayer(std::string, Deck<DeepPtr<Card>>, int=30);

    /**
     * @brief ~CpuPlayer => Class CpuPlayer destructor
     */
    ~CpuPlayer();

    /**
     * @brief clone
     * @return clone of the invocation object
     */
    CpuPlayer* clone() const override;

    /**
     * @brief playTurn
     * @param DLList<DeepPtr<Player>>& => list of players passed by reference
     * @return move made (card played and target player)
     */
    std::string playTurn(DLList<DeepPtr<Player>>&);
};

#endif // CPUPLAYER_H
