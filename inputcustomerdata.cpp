#include "inputcustomerdata.h"
#include "ui_inputcustomerdata.h"
#include <QString>
#include <QDebug>

inputCustomerData::inputCustomerData(customerInfoType *customerList, int listSize, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::inputCustomerData)
{
    ui->setupUi(this);

    database = customerList;

    databaseSize = listSize;
}

inputCustomerData::~inputCustomerData()
{
    delete ui;
}

void inputCustomerData::on_buttonBox_accepted()
{
    qDebug() << "clicked on ok";
    string tempName = ui->nameInput->text().toStdString();               //The name of the customer
    string tempPhoneNumber = ui->phoneNumberInput->text().toStdString(); //The phone number of the customer
    string tempEmail = ui->emailInput->text().toStdString();             //The email of the customer
    string tempBusiness = ui->businessInput->text().toStdString();       //The business the customer belongs to

    qDebug() << ui->nameInput->text();
    qDebug() << QString::fromStdString(tempName);
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

    if (ui->extemelyHighInterestButton->isChecked())
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

    customerInfoType newCustomer(tempName, tempPhoneNumber, tempEmail, tempBusiness, tempInterestLevel);

    qDebug() << "Calling addCustomer";
    database = addCustomer(database, databaseSize, newCustomer);
    databaseSize++;

    qDebug() << "made through accept";
    qDebug() << QString::fromStdString(database[0].getName());

}

customerInfoType * inputCustomerData::getDatabase()
{
    return database;
}

int inputCustomerData::getDatabaseSize()
{
    return databaseSize;
}
