#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QString>
#include "home.h"

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(MainWindow *home, QWidget *parent = nullptr);
    ~Login();

private slots:

private:
    Ui::Login *ui;

   MainWindow *home;
};

#endif // LOGIN_H
