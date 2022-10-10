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
            HealCard* card= static_cast<HealCard*>(c);

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
            SingleAttackCard* card= static_cast<SingleAttackCard*>(c);

            searchPossibleKill(players, targetPlayer, card->getHeartsNumber());
        }
        else if(typeid(*c) == typeid(MultipleAttackCard))
        {
            MultipleAttackCard* card= static_cast<MultipleAttackCard*>(c);

            if(getHealth() > card->getHeartsNumber())//if the multiple attack does not cause the player to commit suicide
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

        if(getHealth()<=10)//first of all check if it should be treated
        {
            findThisTarget(players, targetPlayer);
            searchHealCard(targetCard);
        }

        if(targetCard==-1)//if he doesn't have to cure, he tries to attack to make a kill
            searchPossibleAttack(players, targetCard, targetPlayer);

        if(targetCard==-1)//otherwise random move
        {
            srand(time(NULL));

            targetCard= rand()%getHandSize();
            Card* c= getHand()[targetCard].get();

            if(typeid(*c)==typeid(SingleAttackCard) || typeid(*c)==typeid(DiscardCardsCard))//if the card is single attack or discard cards
            {
                targetPlayer= rand()%players.getSize();

                while(players[targetPlayer].get()==this || !players[targetPlayer]->isInGame())//he doesn't have to target himself and the target obviously has to be alive
                    targetPlayer= rand()%players.getSize();
            }
            else if(typeid(*c)==typeid(HealCard))//if it is a heal card, the target is always himself
            {
                findThisTarget(players, targetPlayer);
            }
            else//other card types
            {
                targetPlayer= rand()%players.getSize();

                while(!players[targetPlayer]->isInGame())//the target must be alive
                    targetPlayer= rand()%players.getSize();
            }
        }

        std::string move= getName()+" uses "+getHand()[targetCard]->getName()+" to "+players[targetPlayer]->getName();

        getHand()[targetCard]->do_effect(players, targetPlayer);
        removeCardFromHand(targetCard);
        drawCard();
        return move;
    }
    else
    {
        removeSkipTurn();
        return getName()+" skips the turn";
    }
};
