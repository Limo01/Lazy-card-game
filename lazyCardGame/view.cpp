#include "view.h"

void View::addMenus(QGridLayout* gridLayout)
{
    QMenuBar* menuBar = new QMenuBar(this);

    game = new QMenu("Game", menuBar);

    menuBar->addMenu(game);

    // Menù "Game"
    game->addAction(new QAction("New Game", game));
    game->addAction(new QAction("Cards Effect", game));
    game->addAction(new QAction("Rules", game));

    menuBar->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    connect(game->actions()[2], SIGNAL(triggered()), this, SLOT(showGameRules()));

    gridLayout->addWidget(menuBar, 0, 0, 1, 3);
};

void View::addCpuPlayersInfo(QGridLayout* gridLayout)
{
    playersInfo.push_back(new CpuPlayerInfo("CpuPlayer#1", this));
    playersInfo.push_back(new CpuPlayerInfo("CpuPlayer#2", this));
    playersInfo.push_back(new CpuPlayerInfo("CpuPlayer#3", this));

    gridLayout->addWidget(playersInfo[0], 1, 0);
    gridLayout->addWidget(playersInfo[1], 1, 1);
    gridLayout->addWidget(playersInfo[2], 1, 2);
};

void View::addPlayerInfo(QGridLayout* gridLayout)
{
    QVBoxLayout* layout= new QVBoxLayout;

    player= new PlayerInfo(this);
    turnLabel= new QLabel("Turn: 1", this);
    playButton= new QPushButton("Make move", this);

    QFont f( "Arial", 14);
    playButton->setFont(f);
    turnLabel->setFont(f);

    playButton->setMinimumWidth(150);
    turnLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    layout->addWidget(player);

    layout->addWidget(turnLabel);
    layout->setAlignment(turnLabel, Qt::AlignHCenter);

    layout->addWidget(playButton, Qt::AlignHCenter);
    layout->setAlignment(playButton, Qt::AlignHCenter);

    gridLayout->addLayout(layout, 2, 1, 2, 1);
};

void View::addLogArea(QGridLayout* gridLayout)
{
    QVBoxLayout* layout= new QVBoxLayout;

    QLabel* titleLog= new QLabel("Moves log", this);
    log= new QTextEdit(this);

    QFont f("Arial", 10, QFont::Bold);
    titleLog->setFont(f);

    log->setReadOnly(true);

    layout->setMargin(10);
    layout->addWidget(titleLog);
    layout->addWidget(log);

    gridLayout->addLayout(layout, 4, 0, 2, 3);
};

View::View(QWidget* parent) : QWidget(parent)
{
    QGridLayout* gridLayout= new QGridLayout(this);

    addMenus(gridLayout);

    addCpuPlayersInfo(gridLayout);

    //user player info
    addPlayerInfo(gridLayout);

    //cards list
    cardsList= new RadioButtonsList("Cards", this);
    gridLayout->addWidget(cardsList, 2, 0, 2, 1);

    //players list
    playersList= new RadioButtonsList("Players", this);
    gridLayout->addWidget(playersList, 2, 2, 2, 1);

    //log text area
    addLogArea(gridLayout);

    gridLayout->setSpacing(10);
    gridLayout->setMargin(0);
    setLayout(gridLayout);
    resize(QSize(1024, 720));
};

void View::setController(Controller* c)
{
    controller= c;

    connect(game->actions()[0], SIGNAL(triggered()), controller, SLOT(restartGame()));
    connect(game->actions()[1], SIGNAL(triggered()), controller, SLOT(cardsDescription()));

    connect(playButton, SIGNAL(clicked()), controller, SLOT(playTurn()));
};

int View::getCardPlayed() const
{
    return cardsList->getButtonClicked();
};

int View::getPlayerTarget() const
{
    return playersList->getButtonClicked();
};

void View::showPlayersInfo(DLList<DeepPtr<Player>>& players)
{
    auto it= ++players.begin();
    for(int i=0; i<playersInfo.size(); i++, it++)
    {
        playersInfo[i]->setHandSize((*it)->getHandSize());
        playersInfo[i]->setDeckSize((*it)->getDeckSize());
        playersInfo[i]->setHeartsNumber((*it)->getHealth());
    }

    player->setHeartsNumber(players[0]->getHealth());
    player->setDeckSize(players[0]->getDeckSize());
};

void View::showPlayerHand(DLList<DeepPtr<Card>>& hand)
{
    cardsList->removeButtons();

    int i=0;
    for(auto it= hand.begin(); it!=hand.end(); it++, i++)
        cardsList->addButton(QString::fromStdString((*it)->getName()), i);
};

void View::showTargetPlayers(DLList<DeepPtr<Player>>& players)
{
    playersList->removeButtons();

    int i=0;
    for(auto it= players.begin(); it!=players.end(); it++, i++)
    {
        if((*it)->isInGame())
            playersList->addButton(QString::fromStdString((*it)->getName()), i);
    }
};

void View::showTurn(int i)
{
    turnLabel->setText("Turn: "+QString::number(i));
};

void View::showMovesLog(const std::string& movesLog)
{
    log->setText(QString::fromStdString(movesLog));
};

void View::showHandCardsDescription(DLList<DeepPtr<Card>>& hand)
{
    QDialog* dialog = new QDialog(this);
    QLabel* dialogText= new QLabel(dialog);

    std::string cardsDescription;

    for(auto it=hand.begin(); it!=hand.end(); it++)
        cardsDescription+= (*it)->getName()+": "+(*it)->getDescription()+"\n";

    dialogText->setText(QString::fromStdString(cardsDescription));

    dialog->setLayout(new QHBoxLayout);
    dialog->layout()->addWidget(dialogText);
    dialog->layout()->setAlignment(Qt::AlignCenter);

    dialog->exec();
};

void View::showGameRules()
{
    QDialog* dialog = new QDialog(this);
    QLabel* dialogText= new QLabel(dialog);

    QString rules=  "Rules: \n"
                    "Each player has a deck of 52 cards. \n"
                    "At the start of the game, each player draws 5 cards. \n"
                    "One card is compulsorily played per turn. \n"
                    "Each card has a different effect (consult the effect of the cards in your hand by clicking on Game -> Cards Effect). \n"
                    "At the end of the turn, a card is drawn. \n"
                    "The goal of the game is to bring all other players' lives to zero. \n"
                    "If a player has no more cards in the deck, 3 hearts are subtracted from him for each card he has to draw."
                    "If multiple skip turn cards are played against a player, that player will consecutively skip one turn for each card.";

    dialogText->setText(rules);

    dialog->setLayout(new QHBoxLayout);
    dialog->layout()->addWidget(dialogText);
    dialog->layout()->setAlignment(Qt::AlignCenter);
    dialog->setFixedSize(580, 150);

    dialog->exec();
};
