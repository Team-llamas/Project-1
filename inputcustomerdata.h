#ifndef INPUTCUSTOMERDATA_H
#define INPUTCUSTOMERDATA_H

#include <QDialog>

namespace Ui {
class inputCustomerData;
}

class inputCustomerData : public QDialog
{
    Q_OBJECT

public:
    explicit inputCustomerData(QWidget *parent = 0);
    ~inputCustomerData();

private:
    Ui::inputCustomerData *ui;
};

#endif // INPUTCUSTOMERDATA_H
