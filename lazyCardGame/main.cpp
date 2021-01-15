#include <QApplication>

#include "model.h"
#include "controller.h"
#include "view.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Model model;
    View view;
    Controller controller;

    controller.setModel(&model);
    controller.setView(&view);

    view.setController(&controller);

    view.show();
    return a.exec();
}
