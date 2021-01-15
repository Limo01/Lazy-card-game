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
     * @brief RadioButtonsList => Costruttore della classe RadioButtonsList
     * @param name => QString, nome del gruppo di radio button
     * @param parent => QWidget*, puntatore al parent
     */
    RadioButtonsList(const QString& name, QWidget* parent= nullptr);

    /**
     * @brief ~RadioButtonsList => Distruttore della classe RadioButtonsList
     */
    ~RadioButtonsList();

    /**
     * @brief addButton => Funzione per aggiungere un radio button alla lista
     * @param name => QString, nome da dare al radio button
     * @param i => int, id da assegnare al radio button
     */
    void addButton(const QString& name, int i);

    /**
     * @brief removeButtons => Funzione per rimuovere tutti i radio button dalla lista
     */
    void removeButtons();

    /**
     * @brief getButtonClicked
     * @return id del bottone attualmente selezionato
     */
    int getButtonClicked() const;
};

#endif // RADIOBUTTONSSLIST_H
