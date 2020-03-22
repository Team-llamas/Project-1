#ifndef DELETECONFIRMATION_H
#define DELETECONFIRMATION_H

#include <QDialog>
#include <QSqlQuery>
#include <QSqlError>
#include <QString>
#include <QDebug>

namespace Ui {
class deleteConfirmation;
}

class deleteConfirmation : public QDialog
{
    Q_OBJECT

public:
    explicit deleteConfirmation(QSqlQuery deleteCustomer, QWidget *parent = 0);
    ~deleteConfirmation();

private slots:
    void on_acceptButtonBox_accepted();

private:
    Ui::deleteConfirmation *ui;

    QSqlQuery deleteQuerier;
};

#endif // DELETECONFIRMATION_H
