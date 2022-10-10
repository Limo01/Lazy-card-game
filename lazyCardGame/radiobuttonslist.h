#ifndef RADIOBUTTONSSLIST_H
#define RADIOBUTTONSSLIST_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QButtonGroup>
#include <QRadioButton>
#include <QScrollArea>
#include <QVector>
#include <QButtonGroup>

class RadioButtonsList : public QWidget
{
    Q_OBJECT
private:
    QVector<QRadioButton*> buttons;
    QButtonGroup* buttonGroup;
    QVBoxLayout* scrollLayout;

public:
    /**
     * @brief RadioButtonsList => Class RadioButtonsList constructor
     * @param name => QString, Radio button group name
     * @param parent => QWidget*, pointer to parent
     */
    RadioButtonsList(const QString& name, QWidget* parent= nullptr);

    /**
     * @brief ~RadioButtonsList => Class RadioButtonsList destructor
     */
    ~RadioButtonsList();

    /**
     * @brief addButton => Function to add a radio button to the list
     * @param name => QString, name to give to the radio button
     * @param i => int, id to assign to the radio button
     */
    void addButton(const QString& name, int i);

    /**
     * @brief removeButtons => Function to remove all radio buttons from the list
     */
    void removeButtons();

    /**
     * @brief getButtonClicked
     * @return id of the currently selected button
     */
    int getButtonClicked() const;
};

#endif // RADIOBUTTONSSLIST_H
