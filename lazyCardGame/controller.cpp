#include "controller.h"

Controller::Controller(QObject* parent): QObject(parent) {};

Controller::~Controller()= default;

void Controller::setModel(Model* m)
{
    model= m;
};

void Controller::setView(View* v)
{
    view= v;

    view->showPlayersInfo(model->getPlayersInfo());
    view->showPlayerHand(model->getPlayersInfo()[0]->getHand());
    view->showTurn(model->getTurnNumber());
    view->showTargetPlayers(model->getPlayersInfo());
    view->showMovesLog(model->getMovesLog());
};

void Controller::playTurn()
{
    if(!model->isGameFinished())
    {
        model->playTurn(view->getCardPlayed(), view->getPlayerTarget());

        view->showPlayersInfo(model->getPlayersInfo());
        view->showPlayerHand(model->getPlayersInfo()[0]->getHand());
        view->showTurn(model->getTurnNumber());
        view->showTargetPlayers(model->getPlayersInfo());
        view->showMovesLog(model->getMovesLog());
    }
};

void Controller::restartGame()
{
    model->restartGame();

    view->showPlayersInfo(model->getPlayersInfo());
    view->showPlayerHand(model->getPlayersInfo()[0]->getHand());
    view->showTurn(model->getTurnNumber());
    view->showTargetPlayers(model->getPlayersInfo());
    view->showMovesLog(model->getMovesLog());
};

void Controller::cardsDescription()
{
    view->showHandCardsDescription(model->getPlayersInfo()[0]->getHand());
};
