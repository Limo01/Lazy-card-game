#include "cpuplayer.h"

void CpuPlayer::findThisTarget(DLList<DeepPtr<Player>>& players, int& targetPlayer) const
{
    int i=0;
    bool found=false;

    for(auto it=players.begin(); !found && it!=players.end(); it++, i++)
    {
        if(it->get()==this)
        {
            found= true;
            targetPlayer=i;
        }
    }
};

void CpuPlayer::searchHealCard(int& targetCard)
{
    int i=0;
    int max=-1;
    Card* c;

    for(auto it= getHand().begin(); it!=getHand().end(); it++, i++)
    {
        c= it->get();

        if(typeid(*c) == typeid(HealCard))
        {
            HealCard* card= static_cast<HealCard*>(it->get());

            if(card->getHeartsNumber()>max)
            {
                targetCard= i;
                max= card->getHeartsNumber();
            }
        }
    }
};

void CpuPlayer::searchPossibleKill(DLList<DeepPtr<Player>>& players, int& targetPlayer, int attackValue) const
{
    int i=0;
    bool found= false;

    for(auto it= players.begin(); !found && it!=players.end(); it++, i++)
    {
        if(it->get()!=this && (*it)->isInGame() && attackValue >= (*it)->getHealth())
        {
            found= true;
            targetPlayer=i;
        }
    }
};

void CpuPlayer::searchPossibleAttack(DLList<DeepPtr<Player>>& players, int& targetCard, int& targetPlayer)
{
    int i=0;
    bool found= false;
    Card* c;

    for(auto it= getHand().begin(); !found && it!=getHand().end(); it++, i++)
    {
        c= it->get();
        if(typeid(*c) == typeid(SingleAttackCard))
        {
            SingleAttackCard* card= static_cast<SingleAttackCard*>(it->get());

            searchPossibleKill(players, targetPlayer, card->getHeartsNumber());
        }
        else if(typeid(*c) == typeid(MultipleAttackCard))
        {
            MultipleAttackCard* card= static_cast<MultipleAttackCard*>(it->get());

            if(getHealth() > card->getHeartsNumber())//se l'attacco multiplo non fa suicidare il player
            {
                searchPossibleKill(players, targetPlayer, card->getHeartsNumber());
            }
        }

        if(targetPlayer!=-1)
        {
            found= true;
            targetCard= i;
        }
    }
};

CpuPlayer::CpuPlayer(std::string n, Deck<DeepPtr<Card>> d, int h): Player(n, d, h){};

CpuPlayer::~CpuPlayer()= default;

CpuPlayer* CpuPlayer::clone() const
{
    return new CpuPlayer(*this);
};

std::string CpuPlayer::playTurn(DLList<DeepPtr<Player>>& players)
{
    if(getTurnsToSkip()==0)
    {
        int targetCard=-1;
        int targetPlayer=-1;

        if(getHealth()<=10)//prima di tutto guarda se si deve curare
        {
            findThisTarget(players, targetPlayer);
            searchHealCard(targetCard);
        }

        if(targetCard==-1)//se non si deve curare, cerca di attaccare per fare una kill
            searchPossibleAttack(players, targetCard, targetPlayer);

        if(targetCard==-1)//altrimenti giocata casuale con l'accortezza di non suicidarsi
        {
            srand(time(NULL));

            targetCard= rand()%getHandSize();
            Card* c= getHand()[targetCard].get();

            if(typeid(*c)==typeid(SingleAttackCard) || typeid(*c)==typeid(DiscardCardsCard))//se la carta è di tipo attacco singolo o scarta carte
            {
                targetPlayer= rand()%players.getSize();

                while(players[targetPlayer].get()==this || !players[targetPlayer]->isInGame())//non deve scegliersi da solo come bersaglio e il target ovviamente deve essere vivo
                    targetPlayer= rand()%players.getSize();
            }
            else if(typeid(*c)==typeid(HealCard))//se è una carta cura, il target è sempre se stesso
            {
                findThisTarget(players, targetPlayer);
            }
            else//altri tipi di carte
            {
                targetPlayer= rand()%players.getSize();

                while(!players[targetPlayer]->isInGame())//il target deve essere vivo
                    targetPlayer= rand()%players.getSize();
            }
        }

        std::string move;
        move= getName()+" usa "+getHand()[targetCard]->getName()+" su "+players[targetPlayer]->getName();

        getHand()[targetCard]->do_effect(players, targetPlayer);
        removeCardFromHand(targetCard);
        drawCard();
        return move;
    }
    else
    {
        removeSkipTurn();
        return getName()+" salta il turno";
    }
};
