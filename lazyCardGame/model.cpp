#include "model.h"

void Model::calculateWinner()
{
    bool winner= false;
    for(auto it=players.begin(); it!=players.end() && !winner; it++)
    {
        if(it->get()->isInGame())
        {
            if(movesLog.at(0)=='\n')
                movesLog="Vittoria di "+(*it)->getName()+"!\n"+movesLog;
            else
                 movesLog="Vittoria di "+(*it)->getName()+"!\n\n"+movesLog;
            winner= true;
        }
    }

    if(!winner)
    {
        if(movesLog.at(0)=='\n')
            movesLog="Nessun vincitore!\n"+movesLog;
        else
            movesLog="Nessun vincitore!\n\n"+movesLog;
    }
};

Model::Model(std::string name): playerName(name), movesLog(""), turn(1), gameFinished(false)
{
    CardCreator creator;
    Deck<DeepPtr<Card>> d= creator.createRandomDeck();

    players.push_back(new Player(playerName, d));
    players.push_back(new CpuPlayer("CPU-Player#1", d));
    players.push_back(new CpuPlayer("CPU-Player#2", d));
    players.push_back(new CpuPlayer("CPU-Player#3", d));

    int begin= rand()%4;
    while(dynamic_cast<CpuPlayer*>(players[begin].get()))
    {
        movesLog= static_cast<CpuPlayer*>(players[begin].get())->playTurn(players)+"\n"+movesLog;
        begin= (begin+1)%4;
    }

    while(!isGameFinished() && players[0]->getTurnsToSkip()>0)//se durante il turno è stata giocata una carta per far saltare il turno al giocatore
    {
        movesLog="\n"+movesLog;

        players[0]->removeSkipTurn();
        movesLog= players[0]->getName() + " salta il turno \n"+movesLog;

        for (auto it = ++players.begin(); it != players.end(); it++)
        {
            if (it->get()->isInGame())
                movesLog= static_cast<CpuPlayer*>(it->get())->playTurn(players)+"\n"+movesLog;
        }
        turn++;
    }
};

Model::~Model()= default;

const std::string& Model::getMovesLog() const
{
    return movesLog;
};

DLList<DeepPtr<Player>>& Model::getPlayersInfo()
{
    return players;
};

int Model::getTurnNumber() const
{
    return turn;
};

void Model::playTurn(int cardTarget, int playerTarget)
{
    if(players[playerTarget]->isInGame())
    {
        if(movesLog!="")
            movesLog="\n"+movesLog;

        if(players[0]->getTurnsToSkip()==0)
        {
            players[0]->getHand()[cardTarget]->do_effect(players, playerTarget);
            movesLog= players[0]->getName()+" usa "+players[0]->getHand()[cardTarget]->getName()+" su "+players[playerTarget]->getName()+"\n"+movesLog;
            players[0]->removeCardFromHand(cardTarget);

            players[0]->drawCard();
        }
        else
        {
            players[0]->removeSkipTurn();
            movesLog= players[0]->getName()+ " salta il turno \n"+movesLog;
        }

        for(auto it=++players.begin(); !isGameFinished() && it!=players.end(); it++)
        {
            if(it->get()->isInGame())
                movesLog= static_cast<CpuPlayer*>(it->get())->playTurn(players)+"\n"+movesLog;
        }
        turn++;

        while(!isGameFinished() && players[0]->getTurnsToSkip()>0)//se durante il turno è stata giocata una carta per far saltare il turno al giocatore
        {
            movesLog="\n"+movesLog;

            players[0]->removeSkipTurn();
            movesLog= players[0]->getName()+ " salta il turno \n"+movesLog;

            for(auto it=++players.begin(); it!=players.end(); it++)
            {
                if(it->get()->isInGame())
                    movesLog= static_cast<CpuPlayer*>(it->get())->playTurn(players)+"\n"+movesLog;
            }
            turn++;
        }

        if(!players[0]->isInGame() && !isGameFinished())
        {
            movesLog="\n"+movesLog;

            auto it= (players.begin())++;
            while(!isGameFinished())
            {
                if(it->get()->isInGame())
                    movesLog= static_cast<CpuPlayer*>(it->get())->playTurn(players)+"\n"+movesLog;
                it++;

                if(it==players.end())
                {
                    it= ++players.begin();
                    turn++;
                    movesLog= "\n"+movesLog;
                }
            }
        }
    }
    else throw std::invalid_argument("Model::playTurn: playerTarget isn't in game");
};

bool Model::isGameFinished()
{
    if(!gameFinished)
    {
        int playersInGame= 0;
        for(auto it=players.begin(); it!=players.end(); it++)
        {
            if(it->get()->isInGame())
                playersInGame++;
        }

        if(playersInGame<2)
        {
            calculateWinner();
            gameFinished= true;
        }
    }

    return gameFinished;
};

void Model::restartGame()
{
    movesLog="";
    turn= 1;
    gameFinished= false;

    CardCreator creator;
    Deck<DeepPtr<Card>> d= creator.createRandomDeck();

    players[0]= new Player(playerName, d);
    players[1]= new CpuPlayer("CPU-Player#1", d);
    players[2]= new CpuPlayer("CPU-Player#2", d);
    players[3]= new CpuPlayer("CPU-Player#3", d);

    int begin= rand()%4;
    while(dynamic_cast<CpuPlayer*>(players[begin].get()))
    {
        movesLog= static_cast<CpuPlayer*>(players[begin].get())->playTurn(players)+"\n"+movesLog;
        begin= (begin+1)%4;
    }

    while(!isGameFinished() && players[0]->getTurnsToSkip()>0)//se durante il turno è stata giocata una carta per far saltare il turno al giocatore
    {
        players[0]->removeSkipTurn();
        movesLog= players[0]->getName() + " salta il turno \n\n"+movesLog;

        for (auto it = ++players.begin(); it != players.end(); it++)
        {
            if (it->get()->isInGame())
                movesLog= static_cast<CpuPlayer*>(it->get())->playTurn(players) + "\n"+movesLog;
        }
        turn++;
    }
};
