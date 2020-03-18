#ifndef SEARCHDATABASE_H
#define SEARCHDATABASE_H

#include <QDialog>
#include "home.h"

namespace Ui {
class SearchDatabase;
}

class SearchDatabase : public QDialog
{
    Q_OBJECT

public:
    explicit SearchDatabase(MainWindow *window, QWidget *parent = nullptr);
    ~SearchDatabase();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::SearchDatabase *ui;

    MainWindow *window;
};

#endif // SEARCHDATABASE_H
