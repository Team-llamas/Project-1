#include "inputcustomerdata.h"
#include "ui_inputcustomerdata.h"

inputCustomerData::inputCustomerData(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::inputCustomerData)
{
    ui->setupUi(this);
}

inputCustomerData::~inputCustomerData()
{
    delete ui;
}
