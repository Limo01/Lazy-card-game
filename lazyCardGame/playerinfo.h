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
     * @brief PlayerInfo => Costruttore della classe PlayerInfo
     * @param parent => QWidget*, puntatore al parent
     * @param heartsN => int, numero di cuori (default 30)
     * @param deckS => int, numero di carte nel mazzo (default 47)
     */
    PlayerInfo(QWidget* parent = nullptr, int heartsN=30, int deckS=47);

    /**
     * @brief setHeartsNumber => Funzione per settare il numero di cuori
     * @param h => int, numero cuori
     */
    void setHeartsNumber(int h);

    /**
     * @brief setDeckSize => Funzione per settare il numero di carte nel mazzo
     * @param s => int, numero carte
     */
    void setDeckSize(int s);
};

#endif // PLAYERINFO_H
