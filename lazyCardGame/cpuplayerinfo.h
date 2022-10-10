#ifndef CPUPLAYERINFO_H
#define CPUPLAYERINFO_H

#include <QString>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QLCDNumber>

class CpuPlayerInfo : public QWidget
{
    Q_OBJECT
private:
    QLabel* handSize;
    QLabel* deckSize;
    QLCDNumber* heartsNumber;

public:
    /**
     * @brief CpuPlayerInfo => Class CpuPlayerInfo constructor
     * @param name => std::string, player name
     * @param parent => QWidget*, pointer to parent
     * @param handS => int, number of cards in the hand (default 5)
     * @param deckS => int, number of cards in the deck (default 47)
     * @param heartsN => int, number of hearts (default 30)
     */
    CpuPlayerInfo(const QString& name, QWidget* parent = nullptr, int handS=5, int deckS=47, int heartsN=30);

    /**
     * @brief setHandSize => Function to set the number of cards in the hand
     * @param s => int, number of cards
     */
    void setHandSize(int s);

    /**
     * @brief setDeckSize => Function to set the number of cards in the deck
     * @param s => int, number of cards
     */
    void setDeckSize(int s);

    /**
     * @brief setHeartsNumber => Function to set the number of hearts
     * @param h => int, number of hearts
     */
    void setHeartsNumber(int h);
};

#endif // CPUPLAYERINFO_H
