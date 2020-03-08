#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

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

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
