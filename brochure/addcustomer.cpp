#include "addcustomer.h"
#include "ui_addcustomer.h"
#include "home.h"

addCustomer::addCustomer(MainWindow *window, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addCustomer)
{
    ui->setupUi(this);

    home = window;

    ui->invalidNameLabel->setVisible(false);
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

       if (home->createCustomer(tempName, tempPhoneNumber, tempEmail, tempBusiness, tempKeyCustomer, tempInterestLevel))
       {
           done(Accepted);
       }
       else
       {
            ui->invalidNameLabel->setVisible(true);
       }



}

void addCustomer::on_acceptCancelButtonBox_accepted()
{

}
