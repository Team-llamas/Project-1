#include "home.h"
#include "login.h"
#include "ui_home.h"
#include "QDebug"
#include <QSqlDatabase>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->BrochureOverview->setHidden(true);

    ui->Window->setCurrentIndex(0);

    QSqlDatabase database = QSqlDatabase::addDatabase("QMYSQL");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_capability_clicked()
{
    ui->Window->setCurrentIndex(1);
}

void MainWindow::on_testimonial_clicked()
{
    ui->Window->setCurrentIndex(3);
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
    ui->Window->setCurrentIndex(4);
}

void MainWindow::on_home_clicked()
{
    ui->Window->setCurrentIndex(0);
}

void MainWindow::on_maint_clicked()
{
    ui->Window->setCurrentIndex(2);
}

void MainWindow::on_pushButton_clicked()
{
    ui->Window->setCurrentIndex(5);
}

void MainWindow::on_administrator_clicked()
{
    Login prompt(this); //The widow that prompts the user to login

    prompt.exec();

//    show();
}

bool MainWindow::AttemptLogin(QString inputPassword, QString inputUserName)
{
    bool loginSuccessful = false; //A boolean that keep track of whether or not the login
                                  //was successful

    for(int index = 0; index < VAILD_ACCOUNT_SIZE; index++)
    {

        if(inputPassword == VALID_PASSWORD[index] && inputUserName == VALID_USERNAME[index])
        {
            ui->Window->setCurrentIndex(5);

            loginSuccessful = true;
        }

    }

    return loginSuccessful;
}

void MainWindow::on_indemnity_clicked()
{
    ui->Window->setCurrentIndex(7);
}

void MainWindow::on_buyNow_clicked()
{
    ui->Window->setCurrentIndex(6);
}

