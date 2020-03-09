#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QString"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


const int VAILD_ACCOUNT_SIZE = 1;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool AttemptLogin(QString inputPassword, QString inputUserName);
private slots:
    void on_capability_clicked();

    void on_testimonial_clicked();

    void on_radioButton_clicked(bool checked);

    void on_HelpButton_clicked(bool checked);

    void on_EnvironmentButton_clicked();

    void on_home_clicked();

    void on_maint_clicked();

    void on_pushButton_clicked();

    void on_administrator_clicked();

private:
    Ui::MainWindow *ui;

    const QString VALID_PASSWORD[VAILD_ACCOUNT_SIZE] = {"World"};

    const QString VALID_USERNAME[VAILD_ACCOUNT_SIZE] = {"Hello"};
};
#endif // MAINWINDOW_H
