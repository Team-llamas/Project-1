#include "purchaseconfirmation.h"
#include "ui_purchaseconfirmation.h"

purchaseConfirmation::purchaseConfirmation(QString name, product bought, MainWindow *window, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::purchaseConfirmation)
{
    ui->setupUi(this);

    customerName = name;

    purchase = bought;

    home = window;

    switch (purchase)
    {
    case BASIC: ui->questionLabel->setText("Are you sure you want to buy the basic maintance plan for $200?");
        break;
    case UPGRADE: ui->questionLabel->setText("Are you sure you want to buy the upgrade maintance plan for $500?");
        break;
    case DELUXE: ui->questionLabel->setText("Are you sure you want to buy the deluxe maintance plan for $1,000?");
        break;
    case IROBOT: ui->questionLabel->setText("Are you want to buy an IRobot Bomb Detector for $10,000?");
    }//end switch (purchase)
}

purchaseConfirmation::~purchaseConfirmation()
{
    delete ui;
}

void purchaseConfirmation::on_confirmationButtonBox_accepted()
{
    home->buyProduct(customerName, purchase);
}
