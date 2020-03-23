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

    /** fn
     * AttemptLogin
     *      This is function will take the user to the admin page if a valid
     *      username and password is passed into the function
     *
     * Precondition:
     *      The user should already of inputted a username and password prior to the
     *      function call
     *
     *      pass in QString inputPassword, QString inputUserName
     *          QString inputPassword - The password the user inputted
     *          QString inputUserName - The username the user inputted
     *
     * Postcondition:
     *      If the username and password passed in matches a username and password
     *      of a valid admin account, then the user is taken the admin page. In that case
     *      a bool value of true is returned. If the username and password passed in don't
     *      match any username and password of a valid admin account, then a bool of false
     *      is returned and no other processing is done by this function.
     */
    bool AttemptLogin(QString inputPassword, QString inputUserName);

    /** fn
     * createCustomer
     *      This function and create a new customer using the data passed in and insert that customer in the customerList table
     *
     * Precondition:
     *      All data fields of the customer should be predetermined before calling this function
     *
     *      pass in QString name, QString address, QString email, QString business, bool keyCustomer, interestLevel interest
     *          QString name     - The name of the customer being created
     *          QString address  - The address of the customer being created
     *          QString email    - The email of the customer being created
     *          QString business - The business of the customer being created
     *
     *          bool keyCustomer - A bool value that is true if the customer is a key customer and false if they are a
     *                             "nice to have" customer
     *
     *          interestLevel interest - An enum value stating the interest level of the customer in terms of the products
     *
     * Postcondition:
     *          If name is valid (ie unique and not null or a empty string) then the data is inserted into a new row in the customerList table. The name field
     *          is also inserted into a new row in productOrders table. Then a bool value of true is returned. If name is invalid then a bool value of false
     *          is returned and no other processing is done.
     */
    bool createCustomer(QString name, QString address, QString email, QString business, bool keyCustomer, interestLevel interest);

    /** fn
     * editCustomer
     *      This function use the data passed in to edit an existing customer in the customerList table
     *
     * Precondition:
     *      All data used to edit the customer's info should be determined before calling this function
     *
     *      pass in QString oldName, QString name, QString address, QString email, QString business, bool keyCustomer, interestLevel interest
     *          QString oldName  - The name of the customer before editing, use to find the customer being editted
     *          QString name     - The new name of the customer
     *          QString address  - The new address of the customer
     *          QString email    - The new email of the customer
     *          QString business - The new business of the customer
     *
     *          bool keyCustomer - A bool value that is true if the customer is a key customer and false if they are a
     *                             "nice to have" customer
     *
     *          interestLevel interest - An enum value stating the interest level of the customer in terms of the products
     *
     * Postcondition:
     *      If the new name is valid (ie unique and not null or a empty string) that data is used to update the data in the row
     *      or customerList with a name value that equal oldName. In addition, a bool value of true is returned. If the name is
     *      changed then is also changed in the productOrders table. If the new name is an invalid name a bool value of false is
     *      returned and no other processing is done.
     */
    bool editCustomer(QString oldName, QString name, QString address, QString email, QString business, bool keyCustomer, interestLevel interest);

    /** fn
     * searchDatabaseResult
     *      This function is the finally step of searching the database. It stores the customer that is found in
     *      lastSearchCustomer so the rest of MainWindow can access the data.
     *
     * Precondition:
     *      The customer being searched for should of already been found prior to calling this function
     *
     *      pass in QSqlQuery customerFound
     *          QSqlQuery customerFound - A query object that is already pointing to the row of customerList
     *                                    that represents the customer that was found.
     *
     * Postcondition:
     *      lastSearchCustomer is assigned to the value of customerFound
     */
    void searchDatabaseResult(QSqlQuery customerFound);

    bool RequestPamphletCopy(QSqlQuery *databaseQuery, QString name);

    /** fn
     * searchDatabaseCancel
     *      This function tells MainWindow that a database search was cancelled.
     *
     * Precondition:
     *      The user cancelled the search of the database
     *
     *      pass in nothing
     *
     * Postcondition:
     *      searchCancelled is set to true, so that the rest MainWindow can tell if a search was cancelled
     */
    void searchDatabaseCancel();

    /** fn
     * buyProduct
     *      This function is used process that a customer has bought a product
     *
     * Precondition:
     *      It should be confirmed that this is the product the customer want to buy and that the customer
     *      is on the customerList before calling this function
     *
     *      pass QString name, product purchase
     *          QString name - The name of the customer making the purchase
     *
     *          product purchase - An enum value the states what product the customer is purchasing
     *
     * Postcondition:
     *      The productOrders table is updated at the row representing the customer who made the
     *      purchase in order the show that the customer has made this purchase.
     */
    void buyProduct(QString name, product purchase);
private slots:

    /** fn
     * on_capability_clicked
     *      This is the slot that is executed when the capability button is clicked
     *
     * Postcondition:
     *      The user is taken to the capability page
     */
    void on_capability_clicked();

    /** fn
     * on_testimonial_clicked
     *      This is the slot that is executed when the testimonial button is clicked
     *
     * Postcondition:
     *      The user is taken to the testimonial page
     */
    void on_testimonial_clicked();

    /** fn
     * This is a dead function that cannot be remove without creating a compile-time error,
     * but will never be called.
     */
    void on_radioButton_clicked(bool checked);

    /** fn
     * on_HelpButton_clicked
     *      This is the slot that is executed when the help button is clicked
     *
     * Postcondition:
     *      If the button is being checked (ie checked is true) then BrochureOverview is made
     *      visible. If the button is being unchecked (ie checked is false) then BrochureOverview is
     *      made invisible.
     */
    void on_HelpButton_clicked(bool checked);

    /** fn
     * on_EnvironmentButton_clicked
     *      This is the slot that is executed when the environment button is clicked
     *
     * Postcondition:
     *      The user is taken to the environment page
     */
    void on_EnvironmentButton_clicked();

    /** fn
     * on_home_clicked
     *      This is the slot that is executed when the home button is clicked
     *
     * Postcondition:
     *      The user is taken to the home page
     */
    void on_home_clicked();

    /** fn
     * on_maint_clicked
     *      This is the slot that is executed when the maintance button is clicked
     *
     * Postcondition:
     *      The user is taken to the maintance page
     */
    void on_maint_clicked();

    /** fn
     * on_capability_clicked
     *      This is the slot that is executed when the capability button is clicked
     *
     * Postcondition:
     *      The user is taken to the capability page
     */
    void on_pushButton_clicked();

    /** fn
     * on_administrator_clicked
     *      This is the slot that is executed when the administrator button is clicked
     *
     * Postcondition:
     *      An instance of login is created and displayed in order to prompt the user to log in with
     *      a valid admin login. If the user successfully login then they will be taken to the admin
     *      page. If the user cancel the login then then are returned to the page they were on before,
     *      and no other processing is done.
     */
    void on_administrator_clicked();

    /** fn
     * on_indemnity_clicked
     *      This is the slot that is executed when the indemnity button is clicked
     *
     * Postcondition:
     *      The user is taken to the indemnity page
     */
    void on_indemnity_clicked();

    /** fn
     * on_buyNow_clicked
     *      This is the slot that is executed when the buy now button is clicked
     *
     * Postcondition:
     *      The user is taken to the buy now page
     */
    void on_buyNow_clicked();

    /** fn
     * on_addCustomerButton_clicked
     *      This is the slot that is executed when the add customer button is clicked
     *
     * Postcondition:
     *      An instance of addCustomer is created and Display in order to prompt the user input data to
     *      create a new customer with. If the user is able to successfully create a new customer then
     *      that customer will be inserted into both the customerList table and the productOrders table.
     *      I
     */
    void on_addCustomerButton_clicked();

    /** fn
     * on_capability_clicked
     *      This is the slot that is executed when the capability button is clicked
     *
     * Postcondition:
     *      The user is taken to the capability page
     */
    void on_pushButton_8_clicked();

    /** fn
     * on_capability_clicked
     *      This is the slot that is executed when the capability button is clicked
     *
     * Postcondition:
     *      The user is taken to the capability page
     */
    void on_clearButton_clicked();

    /** fn
     * on_capability_clicked
     *      This is the slot that is executed when the capability button is clicked
     *
     * Postcondition:
     *      The user is taken to the capability page
     */
    void on_printByNameButton_clicked();

    /** fn
     * on_capability_clicked
     *      This is the slot that is executed when the capability button is clicked
     *
     * Postcondition:
     *      The user is taken to the capability page
     */
    void on_deleteCustomerButton_clicked();

    /** fn
     * on_capability_clicked
     *      This is the slot that is executed when the capability button is clicked
     *
     * Postcondition:
     *      The user is taken to the capability page
     */
    void on_editDatabaseButton_clicked();

    void on_PamphletCopy_clicked();

    /** fn
     * on_capability_clicked
     *      This is the slot that is executed when the capability button is clicked
     *
     * Postcondition:
     *      The user is taken to the capability page
     */
    void on_buyBasicButton_clicked();

    /** fn
     * on_capability_clicked
     *      This is the slot that is executed when the capability button is clicked
     *
     * Postcondition:
     *      The user is taken to the capability page
     */
    void on_pushButton_2_clicked();

    /** fn
     * on_capability_clicked
     *      This is the slot that is executed when the capability button is clicked
     *
     * Postcondition:
     *      The user is taken to the capability page
     */
    void on_buyUpgradeButton_clicked();

    /** fn
     * on_capability_clicked
     *      This is the slot that is executed when the capability button is clicked
     *
     * Postcondition:
     *      The user is taken to the capability page
     */
    void on_buyDeluxeButton_clicked();

    /** fn
     * on_capability_clicked
     *      This is the slot that is executed when the capability button is clicked
     *
     * Postcondition:
     *      The user is taken to the capability page
     */
    void on_buyIRobotButton_clicked();

    /** fn
     * on_capability_clicked
     *      This is the slot that is executed when the capability button is clicked
     *
     * Postcondition:
     *      The user is taken to the capability page
     */
    void on_printKeyByNameButton_clicked();

    /** fn
     * on_capability_clicked
     *      This is the slot that is executed when the capability button is clicked
     *
     * Postcondition:
     *      The user is taken to the capability page
     */
    void on_printProductPurchasesButton_clicked();

    void on_SendPamphletButton_clicked();

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
     *      Nothing needs to be done before calling this function and no values need to be passed in
     *
     * Postcondition:
     *      This function will create and display a searchDatabase object that will allow to user to input a name
     *      of a customer. Once processing of the search is completed, searchCancelled will equal true if the search
     *      was cancelled and false if it completed successfully. If the search completed successfully lastSearchCustomer
     *      will already be pointer to the row in customerList that represents the found customer. All that needs to be done
     *      to access the data is calling the value function of lastSearchCustomer.
     */
    void searchDatabasePrompt();
};
#endif // MAINWINDOW_H
