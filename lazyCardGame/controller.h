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
     * @brief Controller => Class Controller constructor
     * @param parent => QObject*, pointer to parent
     */
    Controller(QObject* parent= nullptr);

    /**
     * @brief ~Controller => Class Controller destructor
     */
    ~Controller();

    /**
     * @brief setModel
     * @param m => Model*, model to assign to the controller
     */
    void setModel(Model* m);

    /**
     * @brief setView
     * @param v => View*, view to assign to the controller
     */
    void setView(View* v);

public slots:
    /**
     * @brief playTurn => Function called when the button to execute the player's move is pressed
     */
    void playTurn();

    /**
     * @brief restartGame => Function called when the button to start a new game is pressed
     */
    void restartGame();

    /**
     * @brief cardsDescription => Function called when the button to see the effect of the cards currently in the hand is pressed
     */
    void cardsDescription();
};

#endif // CONTROLLER_H
