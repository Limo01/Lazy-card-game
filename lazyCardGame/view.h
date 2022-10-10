#ifndef VIEW_H
#define VIEW_H

#include <QAction>
#include <QHBoxLayout>
#include <QLabel>
#include <QMenu>
#include <QMenuBar>
#include <QPushButton>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QWidget>
#include <QVector>
#include <QDialog>

#include "cpuplayerinfo.h"
#include "playerinfo.h"
#include "radiobuttonslist.h"
#include "controller.h"

#include "deepptr.h"
#include "player.h"
#include "card.h"
#include "DLList.h"

class Controller;

class View : public QWidget {
    Q_OBJECT
 private:
    QMenu* game;
    QVector<CpuPlayerInfo*> playersInfo;
    PlayerInfo* player;
    QLabel* turnLabel;
    QPushButton* playButton;
    RadioButtonsList* cardsList;
    RadioButtonsList* playersList;
    QTextEdit* log;

    Controller* controller;

    /**
     * @brief addMenus => Function to create the menu bar
     * @param gridLayout => QGridLayout*, pointer to the main grid layout
     */
    void addMenus(QGridLayout* gridLayout);

    /**
     * @brief addCpuPlayersInfo => Function to create the cpu players info area
     * @param gridLayout => QGridLayout*, pointer to the main grid layout
     */
    void addCpuPlayersInfo(QGridLayout* gridLayout);

    /**
     * @brief addPlayerInfo => Function to create the player info area
     * @param gridLayout => QGridLayout*, pointer to the main grid layout
     */
    void addPlayerInfo(QGridLayout* gridLayout);

    /**
     * @brief addLogArea => Function to create the moves log area
     * @param gridLayout => QGridLayout*, pointer to the main grid layout
     */
    void addLogArea(QGridLayout* gridLayout);
    
public:
    /**
     * @brief View => Class View constructor
     * @param parent => QWidget*, pointer to parent
     */
    View(QWidget *parent = nullptr);

    /**
     * @brief setController
     * @param c => Controller*, pointer to the controller to assign
     */
    void setController(Controller* c);

    /**
     * @brief getCardPlayed
     * @return index of the player selected card
     */
    int getCardPlayed() const;

    /**
     * @brief getPlayerTarget
     * @return index of the player selected target
     */
    int getPlayerTarget() const;

    /**
     * @brief showPlayersInfo => Function to update the values of the players
     * @param players => DLList<DeepPtr<Player>>, players list passed by reference
     */
    void showPlayersInfo(DLList<DeepPtr<Player>>& players);

    /**
     * @brief showPlayerHand => Function to show the player's hand
     * @param hand => DLList<DeepPtr<Card>>, players list passed by reference
     */
    void showPlayerHand(DLList<DeepPtr<Card>>& hand);

    /**
     * @brief showTargetPlayers => Function to show the list of target players
     * @param players => DLList<DeepPtr<Player>>, players list passed by reference
     */
    void showTargetPlayers(DLList<DeepPtr<Player>>& players);

    /**
     * @brief showTurn => Function to show the current shift
     * @param i => int, turn
     */
    void showTurn(int i);

    /**
     * @brief showMovesLog => Function to update the moves log
     * @param movesLog => std::string, log passed by reference
     */
    void showMovesLog(const std::string& movesLog);

    /**
     * @brief showHandCardsDescription => Function to show a Dialog with the description of the cards in the player's hand
     * @param hand => DLList<DeepPtr<Card>>, cards list passed by reference
     */
    void showHandCardsDescription(DLList<DeepPtr<Card>>& hand);

public slots:
    /**
     * @brief showGameRules => Function to show a Dialog where the rules of the game are explained
     */
     void showGameRules();
};

#endif // VIEW_H
