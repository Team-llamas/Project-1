#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_textBrowser_anchorClicked(const QUrl &arg1);

    void on_textBrowser_destroyed();

    void on_infoFrame_destroyed(QObject *arg1);

    void on_pushButton_clicked();

    void on_back_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
