#include "mainwindow.h"
#include "capability.h"
#include "ui_mainwindow.h"
#include "inputcustomerdata.h"
#include <QDebug>

mainWindow::mainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->infoFrame->setHidden(true);

    qDebug() << "calling readFile";
    databaseSize = 0;
    database = readFile(database, databaseSize);
    qDebug() << "Starting database size: " << databaseSize;
//    qDebug() << "First name " << QString::fromStdString(database[0].getName());
}

mainWindow::~mainWindow()
{
    qDebug() << "calling writeFile";
    writeFile(database, databaseSize);

    delete [] database;

    delete ui;
}

void mainWindow::on_textBrowser_anchorClicked(const QUrl &arg1)
{
    ui->mainFrame->setHidden(true);
    ui->infoFrame->setHidden(false);
}

void mainWindow::on_capability_clicked()
{
    capability wind;
    wind.setModal(true);
    hide();
    wind.exec();
    show();
}

void mainWindow::on_detectingBombButton_clicked()
{
    ui->mainFrame->setHidden(true);
    ui->infoFrame->setHidden(false);
    ui->stackedWidget->setCurrentIndex(0);
}

void mainWindow::on_back_clicked()
{
    ui->mainFrame->setHidden(false);
    ui->infoFrame->setHidden(true);
}

void mainWindow::on_testimonial_clicked()
{

}

void mainWindow::on_consumingBombButton_clicked()
{
    ui->mainFrame->setHidden(true);
    ui->infoFrame->setHidden(false);
    ui->stackedWidget->setCurrentIndex(1);
}

void mainWindow::on_reachingBombButton_clicked()
{
    ui->mainFrame->setHidden(true);
    ui->infoFrame->setHidden(false);
    ui->stackedWidget->setCurrentIndex(2);
}

void mainWindow::on_tempButton_clicked()
{
//    home wind;
//    wind.setModal(true);
//    hide();
//    wind.exec();
//    show();
}

void mainWindow::on_addCustomerListButton_clicked()
{
    inputCustomerData screen(database, databaseSize);
    screen.setModal(true);
    hide();
    screen.exec();
    show();

    qDebug() << "updating databaseSize";
    database     = screen.getDatabase();
    databaseSize = screen.getDatabaseSize();
}

customerInfoType * mainWindow::getDatabase()
{
    return database;
}

int mainWindow::getDatabaseSize()
{
    return databaseSize;
}
