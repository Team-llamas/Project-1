#ifndef INPUTCUSTOMERDATA_H
#define INPUTCUSTOMERDATA_H

#include <QDialog>
#include "customerinfotype.h"
#include "database.h"

namespace Ui {
class inputCustomerData;
}

class inputCustomerData : public QDialog
{
    Q_OBJECT

public:
    explicit inputCustomerData(customerInfoType *customerList, int listSize, QWidget *parent = 0);
    ~inputCustomerData();

    customerInfoType * getDatabase();
    int getDatabaseSize();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::inputCustomerData *ui;
    customerInfoType *database;
    int databaseSize;
};

#endif // INPUTCUSTOMERDATA_H
