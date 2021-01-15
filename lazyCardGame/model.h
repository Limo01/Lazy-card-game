#ifndef MODEL_H
#define MODEL_H

#include "DLList.h"
#include "player.h"
#include "cardcreator.h"
#include "cpuplayer.h"

class Model
{
private:
    DLList<DeepPtr<Player>> players;
    std::string playerName;
    std::string movesLog;
    int turn;
    bool gameFinished;

    /**
     * @brief calculateWinner => Funzione per determinare il vincitore e scriverlo nel log
     */
    void calculateWinner();

public:
    /**
     * @brief Model=> Costruttore della classe Model
     * @param std::string => nome del giocatore (non cpu player)
     */
    Model(std::string="Player");

    /**
     * @brief ~Model=> Distruttore della classe Model
     */
    ~Model();

    /**
     * @brief getLogMoves
     * @return log di tutte le mosse effettuate fino a quel momento
     */
    const std::string& getMovesLog() const;

    /**
     * @brief getPlayersInfo
     * @return lista dei giocatori
     */
    DLList<DeepPtr<Player>>& getPlayersInfo();

    /**
     * @brief getTurnNumber
     * @return numero del turno
     */
    int getTurnNumber() const;

    /**
     * @brief playTurn => Funzione per il turno del giocatore
     * @param cardTarget => int, indice della carta da giocare
     * @param playerTarget => int, indice del giocatore sul quale giocare la carta selezionata
     */
    void playTurn(int cardTarget, int playerTarget);

    /**
     * @brief isGameFinished
     * @return true se il gioco è finito, false altrimenti
     */
    bool isGameFinished();

    /**
     * @brief restart => Funzione per cominciare una nuova partita
     */
    void restartGame();
};

#endif // MODEL_H
