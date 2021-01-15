#include "radiobuttonslist.h"

RadioButtonsList::RadioButtonsList(const QString& name, QWidget* parent): QWidget(parent), buttonGroup(new QButtonGroup(this))
{
    QVBoxLayout* mainLayout= new QVBoxLayout(this);

    QLabel* listName= new QLabel(name, this);
    listName->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    QScrollArea* scrollArea= new QScrollArea(this);
    QWidget* scrollWidget= new QWidget(this);

    scrollLayout= new QVBoxLayout(scrollWidget);
    scrollWidget->setLayout(scrollLayout);

    scrollArea->setWidget(scrollWidget);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scrollArea->setWidgetResizable(true);

    QFont f("Arial", 10, QFont::Bold);
    listName->setFont(f);

    mainLayout->addWidget(listName);
    mainLayout->addWidget(scrollArea);
};

RadioButtonsList::~RadioButtonsList()= default;

void RadioButtonsList::addButton(const QString& name, int i)
{
    QRadioButton* button= new QRadioButton(name, this);
    buttons.push_back(button);
    buttonGroup->addButton(button, i);
    scrollLayout->addWidget(button);

    if(buttons.size()==1)
        button->setChecked(true);
};

void RadioButtonsList::removeButtons()
{
    for(int i=0; i<buttons.size(); i++)
    {
        buttonGroup->removeButton(buttons[i]);
        delete buttons[i];
    }
    buttons.clear();
};

int RadioButtonsList::getButtonClicked() const
{
    return buttonGroup->checkedId();
};
