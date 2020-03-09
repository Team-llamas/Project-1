#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


const int SIZE = 1;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_capability_clicked();

    void on_testimonial_clicked();

    void on_radioButton_clicked(bool checked);

    void on_HelpButton_clicked(bool checked);

    void on_EnvironmentButton_clicked();

    void on_home_clicked();

    void on_maint_clicked();

    void on_pushButton_clicked();

    bool AttemptLogin(QString inputPassword[], QString inputUserName[], bool validPassword, bool validUserName);

private:
    Ui::MainWindow *ui;

    QString inputPassword[10];

    QString inputUserName[10];

    bool validPassword;

    bool validUserName;

};
#endif // MAINWINDOW_H
