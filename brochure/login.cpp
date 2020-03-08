#include "login.h"
#include "ui_login.h"

Login::Login(MainWindow *home, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);

    this -> home = home;


}

Login::~Login()
{
    delete ui;
}




