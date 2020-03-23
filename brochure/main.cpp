#include "home.h"
#include <QDebug>

#include <QApplication>

int main(int argc, char *argv[])
{
    //test
    QApplication a(argc, argv);
    MainWindow w;

    qDebug() << "calling copy constructor" << endl;
    MainWindow testCopy(w);
    qDebug() << "After copy constructor" << endl;

    testCopy.show();
    return a.exec();
}
