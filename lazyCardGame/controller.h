#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "view.h"
#include "model.h"

class View;

class Controller: public QObject
{
    Q_OBJECT
private:
    View* view;
    Model* model;

public:
    /**
     * @brief Controller => Costruttore della classe Controller
     * @param parent => QObject*, puntatore al parent
     */
    Controller(QObject* parent= nullptr);

    /**
     * @brief ~Controller => Distruttore della classe Controller
     */
    ~Controller();

    /**
     * @brief setModel
     * @param m => Model*, model da assegnare al controller
     */
    void setModel(Model* m);

    /**
     * @brief setView
     * @param v => View*, view da assegnare al controller
     */
    void setView(View* v);

public slots:
    /**
     * @brief playTurn => Funzione chiamata nel momento in cui viene premuto il bottone per eseguire la mossa del giocatore
     */
    void playTurn();

    /**
     * @brief restartGame => Funzione chiamata quando viene premuto il tasto per cominciare una nuova partita
     */
    void restartGame();

    /**
     * @brief cardsDescription => Funzione chiamata quando viene premuto il tasto per vedere l'effetto delle carte attualmente nella mano
     */
    void cardsDescription();
};

#endif // CONTROLLER_H
