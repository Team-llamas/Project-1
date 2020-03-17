#ifndef ADDCUSTOMER_H
#define ADDCUSTOMER_H

#include <QDialog>
#include "home.h"

namespace Ui {
class addCustomer;
}

class addCustomer : public QDialog
{
    Q_OBJECT

public:
    explicit addCustomer(MainWindow *window, QWidget *parent = 0);
    ~addCustomer();

private slots:
    void on_acceptCancelButtonBox_accepted();

private:
    Ui::addCustomer *ui;

    MainWindow *home;
};

#endif // ADDCUSTOMER_H
