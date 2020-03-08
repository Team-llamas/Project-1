#include "home.h"
#include "capability.h"
#include "testimonial.h"
#include "ui_home.h"
#include "QDebug"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->BrochureOverview->setHidden(true);

    ui->Window->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_capability_clicked()
{
    capability wind;
    wind.setModal(true);
    hide();
    wind.exec();
    show();
}

void MainWindow::on_testimonial_clicked()
{
    Testimonial wind;
    wind.setModal(true);
    hide();
    wind.exec();
    show();
}

void MainWindow::on_HelpButton_clicked(bool checked)
{
    if (checked)
    {
        qDebug() << "checked is true";

    }
    else
    {
        qDebug() << "checked is false";
    }

  ui->BrochureOverview->setHidden(!checked);
}

void MainWindow::on_radioButton_clicked(bool checked)
{

}


void MainWindow::on_EnvironmentButton_clicked()
{
    ui->Window->setCurrentIndex(1);
}

void MainWindow::on_home_clicked()
{
    ui->Window->setCurrentIndex(0);
}
