#ifndef PURCHASECONFIRMATION_H
#define PURCHASECONFIRMATION_H

#include <QDialog>
#include <QString>
#include "home.h"
#include "productenum.h"

namespace Ui {
class purchaseConfirmation;
}

class purchaseConfirmation : public QDialog
{
    Q_OBJECT

public:
    explicit purchaseConfirmation(QString name, product bought, MainWindow *window, QWidget *parent = 0);
    ~purchaseConfirmation();

private slots:
    void on_confirmationButtonBox_accepted();

private:
    Ui::purchaseConfirmation *ui;

    QString customerName;

    product purchase;

    MainWindow *home;
};

#endif // PURCHASECONFIRMATION_H
