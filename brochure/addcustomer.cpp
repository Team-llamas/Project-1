#include "addcustomer.h"
#include "ui_addcustomer.h"
#include "home.h"
#include <QDebug>

addCustomer::addCustomer(MainWindow *window, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addCustomer)
{
    ui->setupUi(this);

    home = window;

    ui->invalidNameLabel->setVisible(false);

    editMode = false;
    editName = "";
}

addCustomer::addCustomer(QString name, QString phoneNumber, QString email, QString business, bool keyCustomer, interestLevel interest, MainWindow *window, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addCustomer)
{
    ui->setupUi(this);

    home = window;

    ui->invalidNameLabel->setVisible(false);

    ui->inputName->setText(name);
    ui->inputPhoneNumber->setText(phoneNumber);
    ui->inputEmail->setText(email);
    ui->inputBusiness->setText(business);

    if (keyCustomer)
    {
        ui->inputKeyCustomer->click();
    }

    switch (interest)
    {
    case NO_INTEREST: ui->noInterestButton->click();
        break;

    case LOW_INTEREST: ui->lowInterestButton->click();
        break;

    case MODERATE_INTEREST: ui->moderateInterestButton->click();
        break;

    case HIGH_INTEREST: ui->highInterestButton->click();
        break;

    case EXTREMELY_HIGH_INTEREST: ui->extremelyHighInterestButton->click();
        break;
    }

    editMode = true;
    editName = name;
}

addCustomer::~addCustomer()
{
    delete ui;
}

void addCustomer::accept()
{
       QString tempName        = ui->inputName->text();        //The name of the customer
       QString tempPhoneNumber = ui->inputPhoneNumber->text(); //The phone number of the customer
       QString tempEmail       = ui->inputEmail->text();       //The email of the customer
       QString tempBusiness    = ui->inputBusiness->text();    //The business the customer belongs to
       bool    tempKeyCustomer = ui->inputKeyCustomer->isChecked(); //A bool value stating whether or not this
                                                                    //customer is a key customer


       interestLevel tempInterestLevel; //The interest level of the customer

       if (tempName == "")
       {
           tempName = "Not Given";
       }

       if (tempPhoneNumber == "")
       {
           tempPhoneNumber = "Not Given";
       }

       if (tempEmail == "")
       {
           tempEmail = "Not Given";
       }

       if (tempBusiness == "")
       {
           tempBusiness = "Not Given";
       }

       if (ui->extremelyHighInterestButton->isChecked())
       {
           tempInterestLevel = EXTREMELY_HIGH_INTEREST;
       }
       else if (ui->highInterestButton->isChecked())
       {
           tempInterestLevel = HIGH_INTEREST;
       }
       else if (ui->moderateInterestButton->isChecked())
       {
           tempInterestLevel = MODERATE_INTEREST;
       }
       else if (ui->lowInterestButton->isChecked())
       {
           tempInterestLevel = LOW_INTEREST;
       }
       else
       {
           tempInterestLevel = NO_INTEREST;
       }

       if (!editMode)
       {
           if (home->createCustomer(tempName, tempPhoneNumber, tempEmail, tempBusiness, tempKeyCustomer, tempInterestLevel))
           {
               done(Accepted);
           }
           else
           {
                ui->invalidNameLabel->setVisible(true);
           }
       }
       else
       {
           qDebug() << "about to call editCustomer";
           if (home->editCustomer(editName, tempName, tempPhoneNumber, tempEmail, tempBusiness, tempKeyCustomer, tempInterestLevel))
           {
               done(Accepted);
           }
           else
           {
                ui->invalidNameLabel->setVisible(true);
           }
       }



}

void addCustomer::on_acceptCancelButtonBox_accepted()
{

}
