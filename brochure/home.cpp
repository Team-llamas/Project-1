#include "home.h"
#include "login.h"
#include "addcustomer.h"
#include "searchdatabase.h"
#include "deleteconfirmation.h"
#include "purchaseconfirmation.h"
#include "ui_home.h"
#include "QDebug"
#include <QSqlError>
#include <QSqlDriver>
#include <QChar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    parentPointer = parent;

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

    bool createMainTableError = databaseQuery->exec("CREATE TABLE IF NOT EXISTS customerList (name TEXT PRIMARY KEY NOT NULL, address TEXT, email TEXT, business TEXT, keyCustomer TEXT, interestLevel TEXT, pamphletWanted TEXT)");

    if (!createMainTableError)
    {
        qDebug() << databaseQuery->lastError().text();

        throw databaseQuery->lastError();
    }

     ui->PamphletCopy->setHidden(false);

    bool createProductTableError = databaseQuery->exec("CREATE TABLE IF NOT EXISTS productOrders (customer TEXT, basic INT, upgrade INT, deluxe INT, robot INT)");

    if (!createProductTableError)
    {
        qDebug() << databaseQuery->lastError().text();

        throw databaseQuery->lastError();
    }

    searchDatabaseCancelled = false;

    ui->RepeatRequest->setVisible(false);
}

MainWindow::MainWindow(const MainWindow& otherWindow)
           :QMainWindow(otherWindow.parentPointer)
           , ui(new Ui::MainWindow)
{
    qDebug() << "made it in copy constructor" << endl;

    *ui = *(otherWindow.ui);

    ui->setupUi(this);

    *databaseQuery = *databaseQuery;

    searchDatabaseCancelled = false;

    database = otherWindow.database;

    qDebug() << "test";

    ui->Window->setCurrentIndex(0);
    qDebug() << "test0.5";
    database = QSqlDatabase::addDatabase("QSQLITE");

    qDebug() << "test2";

    database.setDatabaseName("database.db");

    qDebug() << database.databaseName() << " " << database.connectionName() << endl;

    if (!database.open())
    {
        throw database.lastError();
    }

    databaseQuery = new QSqlQuery;

    bool createMainTableError = databaseQuery->exec("CREATE TABLE IF NOT EXISTS customerList (name TEXT PRIMARY KEY NOT NULL, address TEXT, email TEXT, business TEXT, keyCustomer TEXT, interestLevel TEXT, pamphletWanted TEXT)");

    if (!createMainTableError)
    {
        qDebug() << databaseQuery->lastError().text();

        throw databaseQuery->lastError();
    }

     ui->PamphletCopy->setHidden(false);

    bool createProductTableError = databaseQuery->exec("CREATE TABLE IF NOT EXISTS productOrders (customer TEXT, basic INT, upgrade INT, deluxe INT, robot INT)");

    if (!createProductTableError)
    {
        qDebug() << databaseQuery->lastError().text();

        throw databaseQuery->lastError();
    }


    ui->RepeatRequest->setVisible(false);
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

    databaseQuery->prepare("INSERT INTO customerList (name, address, email, business, keyCustomer, interestLevel, pamphletWanted) "
                           "VALUES (?, ?, ?, ?, ?, ?, ?)");

    if (name == "Not Given")
    {
        databaseQuery->bindValue(0, QVariant(QVariant::String));
    }
    else
    {
        databaseQuery->bindValue(0, name);
    }
    databaseQuery->bindValue(1, phoneNumber);
    databaseQuery->bindValue(2, email);
    databaseQuery->bindValue(3, business);

    if (keyCustomer)
    {
        databaseQuery->bindValue(4, "Key");
    }
    else
    {
        databaseQuery->bindValue(4, "Nice to Have");
    }

    qDebug() << interest;
    switch (interest)
    {
    case NO_INTEREST       : databaseQuery->bindValue(5, "No Interest");
                             break;
    case LOW_INTEREST      : databaseQuery->bindValue(5, "Low Interest");
                             break;
    case MODERATE_INTEREST : databaseQuery->bindValue(5, "Moderate Interest");
                             break;
    case HIGH_INTEREST     : databaseQuery->bindValue(5, "High Interest");
                             break;
    case EXTREMELY_HIGH_INTEREST : databaseQuery->bindValue(5, "Extremely High Interest");
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

        databaseQuery->prepare("INSERT INTO productOrders (customer, basic, upgrade, deluxe, robot) VALUES (?, 0, 0, 0, 0)");

        databaseQuery->bindValue(0, name);

        bool productError = databaseQuery->exec();

        if (!productError)
        {
                qDebug() << databaseQuery->lastError().text();
        }//end if (!productError)
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

bool MainWindow::editCustomer(QString oldName, QString name, QString address, QString email, QString business, bool keyCustomer, interestLevel interest)
{
    bool uniqueName = true; //A boolean value the keeps of whether or not the name was unique

    databaseQuery->prepare("UPDATE customerList SET name=?, address=?, email=?, business=?, keyCustomer=?, interestLevel=? WHERE name=?");

    if (name == "Not Given")
    {
        databaseQuery->bindValue(0, QVariant(QVariant::String));
    }
    else
    {
        databaseQuery->bindValue(0, name);
    }
    databaseQuery->bindValue(1, address);
    databaseQuery->bindValue(2, email);
    databaseQuery->bindValue(3, business);

    if (keyCustomer)
    {
        databaseQuery->bindValue(4, "Key");
    }
    else
    {
        databaseQuery->bindValue(4, "Nice to Have");
    }

    qDebug() << interest;
    switch (interest)
    {
    case NO_INTEREST       : databaseQuery->bindValue(5, "No Interest");
                             break;
    case LOW_INTEREST      : databaseQuery->bindValue(5, "Low Interest");
                             break;
    case MODERATE_INTEREST : databaseQuery->bindValue(5, "Moderate Interest");
                             break;
    case HIGH_INTEREST     : databaseQuery->bindValue(5, "High Interest");
                             break;
    case EXTREMELY_HIGH_INTEREST : databaseQuery->bindValue(5, "Extremely High Interest");
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

        if (name != oldName)
        {
            databaseQuery->prepare("UPDATE productOrders SET customer=?");

            databaseQuery->bindValue(0, name);

            bool updateProductError = databaseQuery->exec();

            if (!updateProductError)
            {
                qDebug() << databaseQuery->lastError().text();
            }//end if (!updateProductError)
        }//end if (name != oldName)
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
            if (index % 7 == 0 && index != 0)
            {
                text.append("\n");

                text.append(QString(" ").rightJustified(DATA_WIDTH, QChar(' '), true) + ' ');
            }
            text.append(databaseQuery->value(index).toString().leftJustified(DATA_WIDTH, QChar(' '), true) + ' ');
        }//end for (int index = 0; index < databaseQuery->size(); index++)
         text.append("\n\n");
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

    retrievalSuccessful = databaseQuery->exec("SELECT * FROM customerList ORDER BY name");

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

void MainWindow::searchDatabaseCancel()
{
    searchDatabaseCancelled = true;
}

void MainWindow::on_deleteCustomerButton_clicked()
{
    searchDatabasePrompt();

    if (!searchDatabaseCancelled)
    {
        deleteConfirmation deleteCustomer(lastCustomerSearched);

        deleteCustomer.setModal(true);

        deleteCustomer.exec();
    }
    else
    {
        searchDatabaseCancelled = false;
    }
}

void MainWindow::on_editDatabaseButton_clicked()
{
    searchDatabasePrompt();

    if (!searchDatabaseCancelled)
    {
        QString tempName          = lastCustomerSearched.value(0).toString(); //The current name of the customer that is being edited
        QString tempPhoneNumber   = lastCustomerSearched.value(1).toString(); //The current phone number of the customer that is being edited
        QString tempEmail         = lastCustomerSearched.value(2).toString(); //The current email of the customer that is being edited
        QString tempBusiness      = lastCustomerSearched.value(3).toString(); //The current business of the customer that is being edited
        QString keyCustomerString = lastCustomerSearched.value(4).toString(); //Whether or not the customer is a key customer
        QString interestString    = lastCustomerSearched.value(5).toString(); //A int value represent the current interest level of the customer
                                                                              //being edited

        bool tempKeyCustomer; //A bool value that true if the customer is a key customer and false otherwise

        interestLevel tempInterest; //The current interest level of the customer that is being edited

        if (keyCustomerString == "Key")
        {
            tempKeyCustomer = true;
        }
        else
        {
            tempKeyCustomer = false;
        }

        if (interestString == "No Interest")
        {
            tempInterest = NO_INTEREST;
        }
        else if (interestString == "Low Interest")
        {
            tempInterest = LOW_INTEREST;
        }
        else if (interestString == "Moderate Interest")
        {
            tempInterest = MODERATE_INTEREST;
        }
        else if (interestString == "High Interest")
        {
            tempInterest = HIGH_INTEREST;
        }
        else if (interestString == "Extremely High Interest")
        {
            tempInterest = EXTREMELY_HIGH_INTEREST;
        }

        addCustomer editCustomerPrompt(tempName, tempPhoneNumber, tempEmail, tempBusiness, tempKeyCustomer, tempInterest, this);

        editCustomerPrompt.setModal(true);

        editCustomerPrompt.exec();
    }//end if (!searchDatabaseCancelled)
    else
    {
        searchDatabaseCancelled = false;
    }//end else (if (!searchDatabaseCancelled))
}

void MainWindow::on_buyBasicButton_clicked()
{
    searchDatabasePrompt();

    if (!searchDatabaseCancelled)
    {
        purchaseConfirmation confirm(lastCustomerSearched.value(0).toString(), BASIC, this);

        confirm.setModal(true);

        confirm.exec();
    }
    else
    {
        searchDatabaseCancelled = false;
    }
}

void MainWindow::buyProduct(QString name, product purchase)
{
    QString purchaseQuery; //A the query being written to record the purchase
    QString productString; //A string that stores the product the customer in buying

    switch (purchase)
    {
    case BASIC: productString = "basic";
        break;
    case UPGRADE: productString = "upgrade";
        break;
    case DELUXE: productString = "deluxe";
        break;
    case IROBOT: productString = "robot";
        break;
    }

    purchaseQuery = "UPDATE productOrders SET " + productString + "=(" + productString + " + 1) WHERE customer='" + name + "'";
    bool buyProductError = databaseQuery->exec(purchaseQuery);

    if (!buyProductError)
    {
        qDebug() << databaseQuery->lastError().text();
    }
}

void MainWindow::on_pushButton_2_clicked()
{

}

void MainWindow::on_buyUpgradeButton_clicked()
{
    searchDatabasePrompt();

    if (!searchDatabaseCancelled)
    {
        purchaseConfirmation confirm(lastCustomerSearched.value(0).toString(), UPGRADE, this);

        confirm.setModal(true);

        confirm.exec();
    }
    else
    {
        searchDatabaseCancelled = false;
    }
}

void MainWindow::on_buyDeluxeButton_clicked()
{
    searchDatabasePrompt();

    if (!searchDatabaseCancelled)
    {
        purchaseConfirmation confirm(lastCustomerSearched.value(0).toString(), DELUXE, this);

        confirm.setModal(true);

        confirm.exec();
    }
    else
    {
        searchDatabaseCancelled = false;
    }
}

void MainWindow::on_buyIRobotButton_clicked()
{
    searchDatabasePrompt();

    if (!searchDatabaseCancelled)
    {
        purchaseConfirmation confirm(lastCustomerSearched.value(0).toString(), IROBOT, this);

        confirm.setModal(true);

        confirm.exec();
    }
    else
    {
        searchDatabaseCancelled = false;
    }
}

void MainWindow::on_printKeyByNameButton_clicked()
{
    //constant
    const int NUM_COLUMNS = 7;  //The number of columns in the database

    //variables
    bool retrievalSuccessful; //A boolean value to check if the query succeeded
    QString text;             //The QString that is displayed on the text edit

    retrievalSuccessful = databaseQuery->exec("SELECT * FROM customerList WHERE keyCustomer='Key' ORDER BY name");

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

void MainWindow::on_printProductPurchasesButton_clicked()
{
    //constant
    const int NUM_COLUMNS = 12;  //The number of columns in the database

    //variables
    bool retrievalSuccessful; //A boolean value to check if the query succeeded
    QString text;             //The QString that is displayed on the text edit

    retrievalSuccessful = databaseQuery->exec("SELECT name, address, email, business, keyCustomer, interestLevel, pamphletWanted, basic, upgrade, deluxe, robot, ((200*basic) + (500*upgrade) + (1000*deluxe) + (10000*robot)) FROM customerList INNER JOIN productOrders ON customerList.name=productOrders.customer ORDER BY customerList.name");

    if (!retrievalSuccessful)
    {
         QSqlError error = databaseQuery->lastError();

         qDebug() << error.text();

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
    text.append(QString("Second Level:").leftJustified(DATA_WIDTH, QChar(' '), true) + ' ');
    text.append(QString("Basic Purchase").leftJustified(DATA_WIDTH, QChar(' '), true) + ' ');
    text.append(QString("Upgrade Purchase").leftJustified(DATA_WIDTH, QChar(' '), true) + ' ');
    text.append(QString("Deluxe Purchase").leftJustified(DATA_WIDTH, QChar(' '), true) + ' ');
    text.append(QString("IRobot Purchase").leftJustified(DATA_WIDTH, QChar(' '), true) + ' ');
    text.append(QString("Total Cost").leftJustified(DATA_WIDTH, QChar(' '), true) + ' ');
    text.append('\n');

    printDatabase(text, NUM_COLUMNS);
}

bool MainWindow::RequestPamphletCopy(QSqlQuery *databaseQuery, QString name)
{
   bool onList = true;

   databaseQuery->prepare("UPDATE customerList SET name=?");

    if(name == "Yes")
    {
        databaseQuery->bindValue(6, QVariant(QVariant::String));
    }
    else
    {
        databaseQuery->bindValue(6, name);
    }

    databaseQuery->bindValue(6, "Yes");

    if(onList)
    {
        ui->Window->setCurrentIndex(0);
    }
    else
    {
        qDebug() << "Customer not found. Please enter name in administrator database." << endl;
    }

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

    catch(QSqlError error)
    {
        if(error.text() == "UNIQUE constraint failed: customerList.name Unable to fetch row" || error.text() == "NOT NULL constraint failed: customerList.name Unable to fetch row")
        {
            onList = false;
        }
        else
        {
            throw error;
        }
    }

    return onList;
}



void MainWindow::on_PamphletCopy_clicked()
{

    bool copySuccessful;

    searchDatabasePrompt();

    if(!searchDatabaseCancelled)
    {

        if(lastCustomerSearched.value(6).toString() == "No")
        {
            ui->RepeatRequest->setVisible(false);

            databaseQuery->prepare("UPDATE customerList SET pamphletWanted='Yes' WHERE name=?");
            databaseQuery->bindValue(0, lastCustomerSearched.value(0).toString());
            copySuccessful = databaseQuery->exec();

            if (!copySuccessful)
            {
                qDebug() << databaseQuery->lastError().text();

                qDebug() << databaseQuery->lastQuery();
            }

        }
        else
        {
            ui->RepeatRequest->setVisible(true);
        }

    }
    else
    {
        searchDatabaseCancelled = false;
    }
}

void MainWindow::on_SendPamphletButton_clicked()
{
    bool copySuccessful;

    searchDatabasePrompt();

    if(!searchDatabaseCancelled)
    {
        if(lastCustomerSearched.value(6).toString() == "Yes")
        {
            databaseQuery->prepare("UPDATE customerList SET pamphletWanted= 'Already Have' WHERE name=?");
            databaseQuery->bindValue(0, lastCustomerSearched.value(0).toString());
            copySuccessful = databaseQuery->exec();

            if (!copySuccessful)
            {
                qDebug() << databaseQuery->lastError().text();

                qDebug() << databaseQuery->lastQuery();
            }

        }
        else if(lastCustomerSearched.value(6).toString() == "No")
        {
            ui->databaseDisplay->setText("Customer didn't request a pamphlet.");
        }
        else
        {
            ui->databaseDisplay->setText("Customer already has a pamphlet.");
        }
    }
    else
    {
        searchDatabaseCancelled = false;
    }

}
