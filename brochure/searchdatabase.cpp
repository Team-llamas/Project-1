#include "searchdatabase.h"
#include "ui_searchdatabase.h"


SearchDatabase::SearchDatabase(MainWindow *window, QWidget *parent)
               :QDialog(parent),
    ui(new Ui::SearchDatabase)
{
    ui->setupUi(this);

    this->window = window;
}

SearchDatabase::~SearchDatabase()
{
    delete ui;
}

void SearchDatabase::on_buttonBox_accepted()
{
    QString inputName;

    inputName = "SELECT * FROM database WHERE name = " + ui->InputText->text();


}
