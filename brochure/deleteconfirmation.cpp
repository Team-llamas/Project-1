#include "deleteconfirmation.h"
#include "ui_deleteconfirmation.h"

deleteConfirmation::deleteConfirmation(QSqlQuery deleteCustomer, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::deleteConfirmation)
{
    //constant
    const int DATA_WIDTH = 15;

    //variable
    QString customerDisplayText = ""; //The QString to be display in customerDisplay

    ui->setupUi(this);

    customerDisplayText.append(QString("Name").leftJustified(DATA_WIDTH, QChar(' '), true) + ' ');
    customerDisplayText.append(QString("Phone Number").leftJustified(DATA_WIDTH, QChar(' '), true) + ' ');
    customerDisplayText.append(QString("Email").leftJustified(DATA_WIDTH, QChar(' '), true) + ' ');
    customerDisplayText.append(QString("Business").leftJustified(DATA_WIDTH, QChar(' '), true) + ' ');
    customerDisplayText.append(QString("Key Customer").leftJustified(DATA_WIDTH, QChar(' '), true) + ' ');
    customerDisplayText.append(QString("Interest Level").leftJustified(DATA_WIDTH, QChar(' '), true) + ' ');
    customerDisplayText.append(QString("Want Pamphlet?").leftJustified(DATA_WIDTH, QChar(' '), true) + ' ');
    customerDisplayText.append('\n');

    for (int index = 0; index < 7; index++)
    {
        customerDisplayText.append(deleteCustomer.value(index).toString().leftJustified(DATA_WIDTH, QChar(' '), true) + ' ');
    }//end for (int index = 0; index < databaseQuery->size(); index++)

    ui->customDisplay->setText(customerDisplayText);

    deleteQuerier = deleteCustomer;
}

deleteConfirmation::~deleteConfirmation()
{
    delete ui;
}

void deleteConfirmation::on_acceptButtonBox_accepted()
{
    QString deleteQuery; //The query for deleting the customer

    deleteQuery = "Delete FROM customerList WHERE name='" + deleteQuerier.value(0).toString() + "'";

    bool deleteError = deleteQuerier.exec(deleteQuery);

    if (!deleteError)
    {
        qDebug() << deleteQuerier.lastError();
    }
}
