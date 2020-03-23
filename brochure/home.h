#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QString"
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "interestlevel.h"

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
    const int DATA_WIDTH  = 15; //The width of the output data

    Ui::MainWindow *ui;

    QSqlQuery *databaseQuery;

    QSqlQuery lastCustomerSearched;

    QSqlDatabase database;

    const QString VALID_PASSWORD[VAILD_ACCOUNT_SIZE] = {"World"};

    const QString VALID_USERNAME[VAILD_ACCOUNT_SIZE] = {"Hello"};

    void printDatabase(QString text, const int NUM_COLUMNS) const;

    void searchDatabasePrompt();
};
#endif // MAINWINDOW_H
