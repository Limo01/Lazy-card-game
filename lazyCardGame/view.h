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
     * @brief addMenus => Funzione per creare la menu bar
     * @param gridLayout => QGridLayout*, puntatore al grid layout principale
     */
    void addMenus(QGridLayout* gridLayout);

    /**
     * @brief addCpuPlayersInfo => Funzione per creare la zona delle informazione dei giocatori controllati dal computer
     * @param gridLayout => QGridLayout*, puntatore al grid layout principale
     */
    void addCpuPlayersInfo(QGridLayout* gridLayout);

    /**
     * @brief addPlayerInfo => Funzione per creare la zona delle informazioni del giocatore
     * @param gridLayout => QGridLayout*, puntatore al grid layout principale
     */
    void addPlayerInfo(QGridLayout* gridLayout);

    /**
     * @brief addLogArea => Funzione per creare la zona del log delle mosse
     * @param gridLayout => QGridLayout*, puntatore al grid layout principale
     */
    void addLogArea(QGridLayout* gridLayout);
    
public:
    /**
     * @brief View => Costruttore della classe View
     * @param parent => QWidget*, puntatore al parent
     */
    View(QWidget *parent = nullptr);

    /**
     * @brief setController
     * @param c => Controller*, puntatore al controller da assegnare
     */
    void setController(Controller* c);

    /**
     * @brief getCardPlayed
     * @return indice della carta selezionata dal giocatore
     */
    int getCardPlayed() const;

    /**
     * @brief getPlayerTarget
     * @return indice del target selezionato dal giocatore
     */
    int getPlayerTarget() const;

    /**
     * @brief showPlayersInfo => Funzione per aggiornare i valori dei giocatori
     * @param players => DLList<DeepPtr<Player>>, lista dei giocatori passati per referenza
     */
    void showPlayersInfo(DLList<DeepPtr<Player>>& players);

    /**
     * @brief showPlayerHand => Funzione per mostrare la mano di carte del giocatore
     * @param hand => DLList<DeepPtr<Card>>, lista delle carte passata per referenza
     */
    void showPlayerHand(DLList<DeepPtr<Card>>& hand);

    /**
     * @brief showTargetPlayers => Funzione per mostrare la lista dei giocatori target
     * @param players => DLList<DeepPtr<Player>>, lista dei giocatori passati per referenza
     */
    void showTargetPlayers(DLList<DeepPtr<Player>>& players);

    /**
     * @brief showTurn => Funzione per mostrare il turno attuale
     * @param i => int, turno
     */
    void showTurn(int i);

    /**
     * @brief showMovesLog => Funzione per aggiornare il log delle mosse
     * @param movesLog => std::string, log passato per referenza
     */
    void showMovesLog(const std::string& movesLog);

    /**
     * @brief showHandCardsDescription => Funzione per mostrare un Dialog con la descrizione della carte nella mano del giocatore
     * @param hand => DLList<DeepPtr<Card>>, lista delle carte passata per referenza
     */
    void showHandCardsDescription(DLList<DeepPtr<Card>>& hand);

public slots:
    /**
     * @brief showGameRules => Funzione per mostrare un Dialog dove vengono spiegate le regole del gioco
     */
     void showGameRules();
};

#endif // VIEW_H
