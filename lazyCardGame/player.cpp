#include "player.h"

Player::Player(const std::string& n, const Deck<DeepPtr<Card>>& d, int h): name(n), health(h), turnsToSkip(0), deck(d)
{
    if(d.getSize() > 5)
    {
        deck.shuffle();

        for(int i=0; i<5; i++)
        {
            hand.push_back(deck.drawCard());
        }
    }
    else throw std::domain_error("Player::Player(std::string, Deck<DeepPtr<Card>>, int): Deck<DeepPtr<Card>> size must be at least 5");
}

Player::~Player()= default;

Player* Player::clone() const
{
    return new Player(*this);
};

std::string Player::getName() const
{
    return name;
};

void Player::setHealth(int h)
{
    health= h;
};

int Player::getHealth() const
{
    return health>=0? health : 0;
};

int Player::getHandSize() const
{
    return hand.getSize();
};

DLList<DeepPtr<Card>>& Player::getHand()
{
    return hand;
};

int Player::getDeckSize() const
{
    return deck.getSize();
};

bool Player::isInGame() const
{
    return health>0;
};

void Player::addSkipTurn()
{
    turnsToSkip++;
};

void Player::removeSkipTurn()
{
    if(turnsToSkip>0)
        turnsToSkip--;
};

int Player::getTurnsToSkip() const
{
    return turnsToSkip;
};

void Player::drawCard()
{
    if(deck.getSize()>0)
        hand.push_back(deck.drawCard());
    else
    {
        health-=3;
    }
};

void Player::removeCardFromHand(int i)
{
    if(hand.getSize()>0)
        hand.remove(i);
    else
    {
        health-=3;
    }
};
