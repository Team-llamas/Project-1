#include "login.h"
#include "ui_login.h"

Login::Login(MainWindow *home, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);

    this -> home = home;

    ui->invalidLogin->setVisible(false);
}

Login::~Login()
{
    delete ui;
}

void Login::accept()
{
    bool loginSuccess; //A boolean value that keeps track of whether or not
                       //the login was successful

    loginSuccess = home->AttemptLogin(ui->InputPassword->text(), ui->InputUsername->text());

    if (loginSuccess)
    {
        done(Accepted);
    }
    else
    {
        ui->invalidLogin->setVisible(true);
    }
}

void Login::on_buttonBox_accepted()
{

}
