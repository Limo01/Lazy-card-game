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
     * @brief CpuPlayerInfo => Costruttore della classe CpuPlayerInfo
     * @param name => std::string, nome del giocatore
     * @param parent => QWidget*, puntatore al parent
     * @param handS => int, numero di carte nella mano (default 5)
     * @param deckS => int, numero di carte nel mazzo (default 47)
     * @param heartsN => int, numero di cuori (default 30)
     */
    CpuPlayerInfo(const QString& name, QWidget* parent = nullptr, int handS=5, int deckS=47, int heartsN=30);

    /**
     * @brief setHandSize => Funzione per settare il numero di carte nella mano
     * @param s => int, numero carte
     */
    void setHandSize(int s);

    /**
     * @brief setDeckSize => Funzione per settare il numero di carte nel mazzo
     * @param s => int, numero carte
     */
    void setDeckSize(int s);

    /**
     * @brief setHeartsNumber => Funzione per settare il numero di cuori
     * @param h => int, numero cuori
     */
    void setHeartsNumber(int h);
};

#endif // CPUPLAYERINFO_H
