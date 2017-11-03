#include <QApplication>
#include <QtWidgets>

#include "mainpresenter.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    mainPresenter *mp = new mainPresenter();

    mp->getView()->show();
    return a.exec();
}
