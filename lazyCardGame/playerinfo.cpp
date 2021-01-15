#include "playerinfo.h"

PlayerInfo::PlayerInfo(QWidget* parent, int heartsN, int deckS): QWidget(parent), heartsNumber(new QLCDNumber(3, this)), deckSize(new QLabel(this))
{
    QVBoxLayout* layout= new QVBoxLayout(this);

    QLabel* infoLabel= new QLabel("Info", this);
    infoLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    infoLabel->setAlignment(Qt::AlignLeft);

    heartsNumber->display(heartsN);
    heartsNumber->setMinimumHeight(50);

    setDeckSize(deckS);
    deckSize->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    deckSize->setAlignment(Qt::AlignHCenter);

    QFont f( "Arial", 14);
    deckSize->setFont(f);

    QFont f2( "Arial", 10, QFont::Bold);
    infoLabel->setFont(f2);

    layout->addWidget(infoLabel);
    layout->addWidget(heartsNumber);
    layout->addWidget(deckSize);
};

void PlayerInfo::setHeartsNumber(int h)
{
    heartsNumber->display(h);
};

void PlayerInfo::setDeckSize(int s)
{
    deckSize->setText("Carte nel mazzo: "+QString::number(s));
};
