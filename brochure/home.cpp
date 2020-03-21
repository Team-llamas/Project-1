#include "home.h"
#include "login.h"
#include "addcustomer.h"
#include "searchdatabase.h"
#include "deleteconfirmation.h"
#include "ui_home.h"
#include "QDebug"
#include <QSqlError>
#include <QSqlDriver>
#include <QChar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->BrochureOverview->setHidden(true);


    ui->Window->setCurrentIndex(0);
    database = QSqlDatabase::addDatabase("QSQLITE");

    database.setDatabaseName("database.db");

    qDebug() << database.databaseName() << " " << database.connectionName() << endl;

    if (!database.open())
    {
        throw database.lastError();
    }

    databaseQuery = new QSqlQuery;

    bool createTableError = databaseQuery->exec("CREATE TABLE IF NOT EXISTS customerList (name TEXT PRIMARY KEY NOT NULL, phoneNumber TEXT, email TEXT, business TEXT, keyCustomer INT, interestLevel TEXT, pamphletWanted TEXT)");

    if (!createTableError)
    {
        qDebug() << databaseQuery->lastError().text();
    }
}

MainWindow::~MainWindow()
{
    delete ui;

    delete databaseQuery;

    database.close();
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

    prompt.setModal(true);

    prompt.exec();
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

bool MainWindow::createCustomer(QString name, QString phoneNumber, QString email, QString business, bool keyCustomer, interestLevel interest)
{
    bool uniqueName = true; //A boolean value the keeps of whether or not the name was unique

    databaseQuery->prepare("INSERT INTO customerList (name, phoneNumber, email, business, keyCustomer, interestLevel, pamphletWanted) "
                           "VALUES (?, ?, ?, ?, ?, ?, ?)");

    if (name == "Not Given")
    {
        databaseQuery->addBindValue(QVariant(QVariant::String));
    }
    else
    {
        databaseQuery->addBindValue(name);
    }
    databaseQuery->addBindValue(phoneNumber);
    databaseQuery->addBindValue(email);
    databaseQuery->addBindValue(business);
    databaseQuery->addBindValue(keyCustomer);

    qDebug() << interest;
    switch (interest)
    {
    case NO_INTEREST       : databaseQuery->addBindValue("No Interest");
                             break;
    case LOW_INTEREST      : databaseQuery->addBindValue("Low Interest");
                             break;
    case MODERATE_INTEREST : databaseQuery->addBindValue("Moderate Interest");
                             break;
    case HIGH_INTEREST     : databaseQuery->addBindValue("High Interest");
                             break;
    case EXTREMELY_HIGH_INTEREST : databaseQuery->addBindValue("Extremely High Interest");
                                   break;

    }

    databaseQuery->bindValue(6, "No");

    try
    {
        bool check = databaseQuery->exec();
        if (!check)
        {
            qDebug() << databaseQuery->lastError().text();

            throw databaseQuery->lastError();
        }//end if (!check)
        else
        {
            qDebug() << databaseQuery->lastQuery();
            databaseQuery->exec("SELECT * FROM customerList WHERE name=" + name);
            if (databaseQuery->next())
            {
                qDebug() << "The customer named " << databaseQuery->value(0) << " has successfully been added";
            }//end if (databaseQuery->next())
        }//end else (if (!checked))
    }//end try
    catch (QSqlError error)
    {
        if (error.text() == "UNIQUE constraint failed: customerList.name Unable to fetch row" || error.text() == "NOT NULL constraint failed: customerList.name Unable to fetch row")
        {
            uniqueName = false;
        }//end f (error.text() == "UNIQUE constraint failed: customerList.name Unable to fetch row")
        else
        {
            throw error;
        }

    }//end catch (QsqlError error)

    return uniqueName;
}

bool MainWindow::editCustomer(QString oldName, QString name, QString phoneNumber, QString email, QString business, bool keyCustomer, interestLevel interest)
{
    bool uniqueName = true; //A boolean value the keeps of whether or not the name was unique

    databaseQuery->prepare("UPDATE customerList SET name=?, phoneNumber=?, email=?, business=?, keyCustomer=?, interestLevel=? WHERE name=?");

    if (name == "Not Given")
    {
        databaseQuery->addBindValue(QVariant(QVariant::String));
    }
    else
    {
        databaseQuery->addBindValue(name);
    }
    databaseQuery->addBindValue(phoneNumber);
    databaseQuery->addBindValue(email);
    databaseQuery->addBindValue(business);
    databaseQuery->addBindValue(keyCustomer);

    qDebug() << interest;
    switch (interest)
    {
    case NO_INTEREST       : databaseQuery->addBindValue("No Interest");
                             break;
    case LOW_INTEREST      : databaseQuery->addBindValue("Low Interest");
                             break;
    case MODERATE_INTEREST : databaseQuery->addBindValue("Moderate Interest");
                             break;
    case HIGH_INTEREST     : databaseQuery->addBindValue("High Interest");
                             break;
    case EXTREMELY_HIGH_INTEREST : databaseQuery->addBindValue("Extremely High Interest");
                                   break;

    }

    databaseQuery->bindValue(6, oldName);

    try
    {
        bool check = databaseQuery->exec();
        if (!check)
        {
            qDebug() << databaseQuery->lastError().text();

            throw databaseQuery->lastError();
        }//end if (!check)
        else
        {
            qDebug() << databaseQuery->lastQuery();
            databaseQuery->exec("SELECT * FROM customerList WHERE name=" + name);
            if (databaseQuery->next())
            {
                qDebug() << "The customer named " << databaseQuery->value(0) << " has successfully been added";
            }//end if (databaseQuery->next())
        }//end else (if (!checked))
    }//end try
    catch (QSqlError error)
    {
        if (error.text() == "UNIQUE constraint failed: customerList.name Unable to fetch row" || error.text() == "NOT NULL constraint failed: customerList.name Unable to fetch row")
        {
            uniqueName = false;
        }//end f (error.text() == "UNIQUE constraint failed: customerList.name Unable to fetch row")
        else
        {
            throw error;
        }

    }//end catch (QsqlError error)

    return uniqueName;
}

void MainWindow::on_addCustomerButton_clicked()
{
    addCustomer prompt(this); //The Qdialog that allow the user to input data

    prompt.setModal(true);

    prompt.exec();
}

void MainWindow::on_pushButton_8_clicked()
{
   //constant
   const int NUM_COLUMNS = 7;  //The number of columns in the database

   //variables
   bool retrievalSuccessful; //A boolean value to check if the query succeeded
   QString text;             //The QString that is displayed on the text edit

   retrievalSuccessful = databaseQuery->exec("SELECT * FROM customerList");

   if (!retrievalSuccessful)
   {
        qDebug() << "yep" << endl;
        QSqlError error = databaseQuery->lastError();

        qDebug() << error.text() << endl;

        throw error;
   }

   text = "Name";
   text = text.leftJustified(DATA_WIDTH, QChar(' '), true) + ' ';
   text.append(QString("Phone Number").leftJustified(DATA_WIDTH, QChar(' '), true) + ' ');
   text.append(QString("Email").leftJustified(DATA_WIDTH, QChar(' '), true) + ' ');
   text.append(QString("Business").leftJustified(DATA_WIDTH, QChar(' '), true) + ' ');
   text.append(QString("Key Customer").leftJustified(DATA_WIDTH, QChar(' '), true) + ' ');
   text.append(QString("Interest Level").leftJustified(DATA_WIDTH, QChar(' '), true) + ' ');
   text.append(QString("Want Pamphlet?").leftJustified(DATA_WIDTH, QChar(' '), true) + ' ');
   text.append('\n');

   printDatabase(text, NUM_COLUMNS);
}

void MainWindow::printDatabase(QString text, const int NUM_COLUMNS) const
{
    bool empty = true; //A boolean that checks if the database is empty

    while (databaseQuery->next())
    {
        empty = false;

        for (int index = 0; index < NUM_COLUMNS; index++)
        {
            text.append(databaseQuery->value(index).toString().leftJustified(DATA_WIDTH, QChar(' '), true) + ' ');
        }//end for (int index = 0; index < databaseQuery->size(); index++)
         text = text + '\n';
     }//end while (databaseQuery->next())

     if (empty)
     {
         text = "The database is empty";
     }

     ui->databaseDisplay->setText(text);
}

void MainWindow::on_clearButton_clicked()
{
    ui->databaseDisplay->setText("");
}

void MainWindow::on_printByNameButton_clicked()
{
    //constant
    const int NUM_COLUMNS = 7;  //The number of columns in the database

    //variables
    bool retrievalSuccessful; //A boolean value to check if the query succeeded
    QString text;             //The QString that is displayed on the text edit

    retrievalSuccessful = databaseQuery->exec("SELECT * FROM customerList ORDEREDBY name");

    if (!retrievalSuccessful)
    {
         qDebug() << "yep" << endl;
         QSqlError error = databaseQuery->lastError();

         qDebug() << error.text() << endl;

         throw error;
    }

    text = "Name";
    text = text.leftJustified(DATA_WIDTH, QChar(' '), true) + ' ';
    text.append(QString("Phone Number").leftJustified(DATA_WIDTH, QChar(' '), true) + ' ');
    text.append(QString("Email").leftJustified(DATA_WIDTH, QChar(' '), true) + ' ');
    text.append(QString("Business").leftJustified(DATA_WIDTH, QChar(' '), true) + ' ');
    text.append(QString("Key Customer").leftJustified(DATA_WIDTH, QChar(' '), true) + ' ');
    text.append(QString("Interest Level").leftJustified(DATA_WIDTH, QChar(' '), true) + ' ');
    text.append(QString("Want Pamphlet?").leftJustified(DATA_WIDTH, QChar(' '), true) + ' ');
    text.append('\n');

    printDatabase(text, NUM_COLUMNS);
}

void MainWindow::searchDatabasePrompt()
{
    SearchDatabase search(this); //The Qdialog that prompts the user to enter their name

    search.setModal(true);

    search.exec();
}

void MainWindow::searchDatabaseResult(QSqlQuery customerFound)
{
    lastCustomerSearched = customerFound;
}


void MainWindow::on_deleteCustomerButton_clicked()
{
    searchDatabasePrompt();

    deleteConfirmation deleteCustomer(lastCustomerSearched);

    deleteCustomer.setModal(true);

    deleteCustomer.exec();
}

void MainWindow::on_editDatabaseButton_clicked()
{
    searchDatabasePrompt();

    QString tempName        = lastCustomerSearched.value(0).toString(); //The current name of the customer that is being edited
    QString tempPhoneNumber = lastCustomerSearched.value(1).toString(); //The current phone number of the customer that is being edited
    QString tempEmail       = lastCustomerSearched.value(2).toString(); //The current email of the customer that is being edited
    QString tempBusiness    = lastCustomerSearched.value(3).toString(); //The current business of the customer that is being edited
    bool    tempKeyCustomer = lastCustomerSearched.value(4).toBool();   //A boolean that is true if the customer currently being edited is
                                                                        //currently a key customer and false otherwise
    QString interestString  = lastCustomerSearched.value(5).toString(); //A int value represent the current interest level of the customer
                                                                        //being edited

    interestLevel tempInterest; //The current interest level of the customer that is being edited

    if (interestString == "N0 Interest")
    {
        tempInterest = NO_INTEREST;
    }
    else if (interestString == "Low Interest")
    {
        tempInterest = LOW_INTEREST;
    }
    else if (interestString == "Low Interest")
    {
        tempInterest = MODERATE_INTEREST;
    }
    else if (interestString == "Low Interest")
    {
        tempInterest = HIGH_INTEREST;
    }
    else if (interestString == "Low Interest")
    {
        tempInterest = EXTREMELY_HIGH_INTEREST;
    }

    addCustomer editCustomerPrompt(tempName, tempPhoneNumber, tempEmail, tempBusiness, tempKeyCustomer, tempInterest, this);

    editCustomerPrompt.setModal(true);

    editCustomerPrompt.exec();
}
