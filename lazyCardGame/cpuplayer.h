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
     * @brief findThisTarget => Funzione per trovare l'indice del giocatore che chiama la funzione all'interno della lista players
     * @param players => DLList<DeepPtr<Player>>, lista dei giocatori passata per referenza
     * @param targetPlayer => int, variabile passata per referenza che conterrà l'indice del giocatore
     */
    void findThisTarget(DLList<DeepPtr<Player>>& players, int& targetPlayer) const;

    /**
     * @brief searchHealCard => Funzione per cercare la carta salute con valore più alto all'interno della mano
     * @param targetCard => int, variabile passata per referenza che conterrà l'indice della carta all'interno della mano del giocatore (se la trova, altrimenti conterrà il valore iniziale)
     */
    void searchHealCard(int& targetCard);

    /**
     * @brief searchPossibleKill => Funzione per vedere se è possibbile uccidere uno tra i giocatori usando un dato valore di attacco
     * @param players => DLList<DeepPtr<Player>>, lista dei giocatori passata per referenza
     * @param targetPlayer => int, variabile passata per referenza che conterrà l'indice del giocatore selezionato (se lo trova, altrimenti conterrà il valore iniziale)
     * @param attackValue => int, valore di attacco della carta che vogliamo usare
     */
    void searchPossibleKill(DLList<DeepPtr<Player>>& players, int& targetPlayer, int attackValue) const;

    /**
     * @brief searchPossibleAttack => Funzione per cercare se è possibbile sferrare un attacco fatale a un giocatore
     * @param players => DLList<DeepPtr<Player>>, lista dei giocatori passata per referenza
     * @param targetCard => int, variabile passata per referenza che conterrà l'indice della carta attacco all'interno della mano del giocatore (solo se ha trovato un possibile attacco, altrimenti conterrà il valore iniziale)
     * @param targetPlayer => int, variabile passata per referenza che conterrà l'indice del giocatore selezionato (solo se ha trovato un possibile attacco, altrimenti conterrà il valore iniziale)
     */
    void searchPossibleAttack(DLList<DeepPtr<Player>>& players, int& targetCard, int& targetPlayer);

public:
    /**
     * @brief CpuPlayer => Costruttore della classe CpuPlayer
     * @param std::string => nome del giocatore
     * @param Deck<DeepPtr<Card>> => deck di carte
     * @param int => vita iniziale del giocatore (valore di default=30);
     */
    CpuPlayer(std::string, Deck<DeepPtr<Card>>, int=30);

    /**
     * @brief ~CpuPlayer => Distruttore della classe CpuPlayer
     */
    ~CpuPlayer();

    /**
     * @brief clone
     * @return clone dell'oggetto di invocazione
     */
    CpuPlayer* clone() const override;

    /**
     * @brief playTurn
     * @param DLList<DeepPtr<Player>>& => lista dei giocatori passata per referenza
     * @return mossa effettuata (carta giocata e giocatore target)
     */
    std::string playTurn(DLList<DeepPtr<Player>>&);
};

#endif // CPUPLAYER_H
