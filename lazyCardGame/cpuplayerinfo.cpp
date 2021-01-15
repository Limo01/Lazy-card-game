#include "cpuplayerinfo.h"

CpuPlayerInfo::CpuPlayerInfo(const QString& name, QWidget* parent, int handS, int deckS, int heartsN): QWidget(parent), handSize(new QLabel(this)), deckSize(new QLabel(this)), heartsNumber(new QLCDNumber(3, this))
{
    QVBoxLayout* layout= new QVBoxLayout(this);

    QLabel* playerName= new QLabel(name, this);
    playerName->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    playerName->setAlignment(Qt::AlignLeft);

    setHandSize(handS);
    handSize->setMinimumHeight(30);
    handSize->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    handSize->setAlignment(Qt::AlignHCenter);

    setDeckSize(deckS);
    deckSize->setMinimumHeight(20);
    deckSize->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    deckSize->setAlignment(Qt::AlignHCenter);

    setHeartsNumber(heartsN);
    heartsNumber->setMinimumHeight(50);

    QFont f("Arial", 10, QFont::Bold);
    playerName->setFont(f);

    QFont f2("Arial", 10);
    handSize->setFont(f2);
    deckSize->setFont(f2);

    layout->addWidget(playerName);
    layout->addWidget(handSize);
    layout->addWidget(deckSize);
    layout->addWidget(heartsNumber);
};

void CpuPlayerInfo::setHandSize(int s)
{
    handSize->setText("Carte nella mano: "+QString::number(s));
};

void CpuPlayerInfo::setDeckSize(int s)
{
    deckSize->setText("Carte nel mazzo: "+QString::number(s));
};

void CpuPlayerInfo::setHeartsNumber(int h)
{
    heartsNumber->display(h);
};
