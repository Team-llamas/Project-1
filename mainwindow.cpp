#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->infoFrame->setHidden(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_textBrowser_anchorClicked(const QUrl &arg1)
{
    ui->mainFrame->setHidden(true);
    ui->infoFrame->setHidden(false);
}

void MainWindow::on_textBrowser_destroyed()
{

}

void MainWindow::on_infoFrame_destroyed(QObject *arg1)
{

}

void MainWindow::on_pushButton_clicked()
{
    ui->mainFrame->setHidden(true);
    ui->infoFrame->setHidden(false);
}

void MainWindow::on_back_clicked()
{
    ui->mainFrame->setHidden(false);
    ui->infoFrame->setHidden(true);
}
