#include "mainwindow.h"
#include "capability.h"
#include "ui_mainwindow.h"

home::home(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->infoFrame->setHidden(true);
}

home::~home()
{
    delete ui;
}

void home::on_textBrowser_anchorClicked(const QUrl &arg1)
{
    ui->mainFrame->setHidden(true);
    ui->infoFrame->setHidden(false);
}

void home::on_capability_clicked()
{
    capability wind;
    wind.setModal(true);
    hide();
    wind.exec();
    show();
}

void home::on_detectingBombButton_clicked()
{
    ui->mainFrame->setHidden(true);
    ui->infoFrame->setHidden(false);
    ui->stackedWidget->setCurrentIndex(0);
}

void home::on_back_clicked()
{
    ui->mainFrame->setHidden(false);
    ui->infoFrame->setHidden(true);
}

void home::on_testimonial_clicked()
{

}

void home::on_consumingBombButton_clicked()
{
    ui->mainFrame->setHidden(true);
    ui->infoFrame->setHidden(false);
    ui->stackedWidget->setCurrentIndex(1);
}

void home::on_reachingBombButton_clicked()
{
    ui->mainFrame->setHidden(true);
    ui->infoFrame->setHidden(false);
    ui->stackedWidget->setCurrentIndex(2);
}

void home::on_tempButton_clicked()
{
    home wind;
    wind.setModal(true);
    hide();
    wind.exec();
    show();
}
