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
     * @brief Model=> Class Model constructor
     * @param std::string => player name (not cpu player)
     */
    Model(std::string="Player");

    /**
     * @brief ~Model=> Class Model destructor
     */
    ~Model();

    /**
     * @brief getLogMoves
     * @return log of all the moves made up to that moment
     */
    const std::string& getMovesLog() const;

    /**
     * @brief getPlayersInfo
     * @return list of players
     */
    DLList<DeepPtr<Player>>& getPlayersInfo();

    /**
     * @brief getTurnNumber
     * @return turn number
     */
    int getTurnNumber() const;

    /**
     * @brief playTurn => Player turn function
     * @param cardTarget => int, index of the card to be played
     * @param playerTarget => int, index of the player on which play the selected card
     */
    void playTurn(int cardTarget, int playerTarget);

    /**
     * @brief isGameFinished
     * @return true if the game is over, false otherwise
     */
    bool isGameFinished();

    /**
     * @brief restart => Function to start a new game
     */
    void restartGame();
};

#endif // MODEL_H
