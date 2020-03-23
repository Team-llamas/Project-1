#include "searchdatabase.h"
#include "ui_searchdatabase.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>


SearchDatabase::SearchDatabase(MainWindow *window, QWidget *parent)
               :QDialog(parent),
    ui(new Ui::SearchDatabase)
{
    ui->setupUi(this);

    this->window = window;

    ui->notFoundLabel->setVisible(false);
}

SearchDatabase::~SearchDatabase()
{
    delete ui;
}

void SearchDatabase::on_buttonBox_accepted()
{

}

void SearchDatabase::accept()
{
    QString   inputName;   //The query that searches the database
    QSqlQuery searchQuery; //The query object being use to search the database

    inputName = "SELECT * FROM customerList WHERE name='" + ui->InputText->text() + "'";

    bool searchError = searchQuery.exec(inputName);

    if (!searchError)
    {
        qDebug() << searchQuery.lastError();
        qDebug() << searchQuery.lastQuery();
    }//end if (!searchError)

    if (searchQuery.next())
    {
        window->searchDatabaseResult(searchQuery);

        done(Accepted);
    }//end if (searchQuery.next())
    else
    {
        ui->notFoundLabel->setVisible(true);
    }

}

void SearchDatabase::on_buttonBox_rejected()
{
    window->searchDatabaseCancel();
}
