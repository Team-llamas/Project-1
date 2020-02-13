#include "mainwindow.h"
#include <QApplication>

//test
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    cout << "Hello World" << endl;

    return a.exec();
}
