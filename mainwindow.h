#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "customerinfotype.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class mainWindow : public QMainWindow
{
    Q_OBJECT

public:
    mainWindow(QWidget *parent = nullptr);
    ~mainWindow();

    customerInfoType * getDatabase();
    int getDatabaseSize();
private slots:
    void on_capability_clicked();

    void on_testimonial_clicked();
private slots:
    void on_textBrowser_anchorClicked(const QUrl &arg1);

    void on_detectingBombButton_clicked();

    void on_back_clicked();

    void on_consumingBombButton_clicked();

    void on_reachingBombButton_clicked();

    void on_tempButton_clicked();

    void on_addCustomerListButton_clicked();

private:
    Ui::MainWindow *ui;
    customerInfoType *database;
    int databaseSize;
};
#endif // MAINWINDOW_H
