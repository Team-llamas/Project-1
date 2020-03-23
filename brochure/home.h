#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QString"
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "interestlevel.h"
#include "productenum.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


const int VAILD_ACCOUNT_SIZE = 1;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool AttemptLogin(QString inputPassword, QString inputUserName);

    bool createCustomer(QString name, QString phoneNumber, QString email, QString business, bool keyCustomer, interestLevel interest);

    bool editCustomer(QString oldName, QString name, QString phoneNumber, QString email, QString business, bool keyCustomer, interestLevel interest);

    void searchDatabaseResult(QSqlQuery customerFound);

    bool RequestPamphletCopy(QSqlQuery *databaseQuery, QString name);

    void searchDatabaseCancel();

    void buyProduct(QString name, product purchase);

private slots:
    void on_capability_clicked();

    void on_testimonial_clicked();

    void on_radioButton_clicked(bool checked);

    void on_HelpButton_clicked(bool checked);

    void on_EnvironmentButton_clicked();

    void on_home_clicked();

    void on_maint_clicked();

    void on_pushButton_clicked();

    void on_administrator_clicked();

    void on_indemnity_clicked();

    void on_buyNow_clicked();

    void on_addCustomerButton_clicked();

    void on_pushButton_8_clicked();

    void on_clearButton_clicked();

    void on_printByNameButton_clicked();

    void on_deleteCustomerButton_clicked();

    void on_editDatabaseButton_clicked();

    void on_PamphletCopy_clicked();

private:

    void on_buyBasicButton_clicked();

    void on_pushButton_2_clicked();

    void on_buyUpgradeButton_clicked();

    void on_buyDeluxeButton_clicked();

    void on_buyIRobotButton_clicked();

    void on_printKeyByNameButton_clicked();

    void on_printProductPurchasesButton_clicked();

private:
    const int DATA_WIDTH  = 15; //!The width of the output data

    Ui::MainWindow *ui; //!Qt generated ui pointer, for accessing the widgets of the window

    QSqlQuery *databaseQuery; //!A pointer to the primary query object for the sql database

    QSqlQuery lastCustomerSearched; //!A QsqlQuery that is used to store the customer found during a search

    bool searchDatabaseCancelled; //!A bool value that is only true when a search of the database was cancelled

    QSqlDatabase database; //!The database object interfacing with database for this program

    const QString VALID_PASSWORD[VAILD_ACCOUNT_SIZE] = {"World"}; //!A const array of all valid admin usernames

    const QString VALID_USERNAME[VAILD_ACCOUNT_SIZE] = {"Hello"}; //!A const array of all valid admin passwords, positionally corresponding
                                                                  //!to the array of valid username

    /** fn
     * printDatabase
     *      Use to print out the database to the databaseDisplay QTextEdit after executing a SELECT query to retrieve the
     *      data that is intended to be printed out
     *
     * Precondition:
     *      A SELECT was executed through databaseQuery to retrieve the data that is to be printed out, and
     *      any type of header is prepare BEFORE calling this function
     *
     *      pass in QString text, const int NUM_COLUMNS
     *          QString text - The QString that will be displayed in databaseDisplay, this QString should
     *                         contain the header of the data with a /n at the end when calling the function
     *
     *          const int NUM_COLUMNS - A int value that tells printDatabase how many columns of data is being
     *                                  printed out.
     *
     * Postcondition:
     *      The data is appended to text in a formatted then text is displayed in databaseDisplay
     */
    void printDatabase(QString text, const int NUM_COLUMNS) const;

    /** fn
     * searchDatabasePrompt
     *      Use this function to begin a search of the database
     *
     * Precondition:
     *
     */
    void searchDatabasePrompt();
};
#endif // MAINWINDOW_H
