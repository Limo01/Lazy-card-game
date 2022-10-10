#ifndef PLAYERINFO_H
#define PLAYERINFO_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QLCDNumber>
#include <QPushButton>
#include <QFont>

class PlayerInfo: public QWidget
{
    Q_OBJECT
private:
    QLCDNumber* heartsNumber;
    QLabel* deckSize;

public:
    /**
     * @brief PlayerInfo => Class PlayerInfo constructor
     * @param parent => QWidget*, pointer to parent
     * @param heartsN => int, number of hearts (default 30)
     * @param deckS => int, number of cards in the deck (default 47)
     */
    PlayerInfo(QWidget* parent = nullptr, int heartsN=30, int deckS=47);

    /**
     * @brief setHeartsNumber => Function to set the number of hearts
     * @param h => int, hearts number
     */
    void setHeartsNumber(int h);

    /**
     * @brief setDeckSize => Function to set the number of cards in the deck
     * @param s => int, cards number
     */
    void setDeckSize(int s);
};

#endif // PLAYERINFO_H
