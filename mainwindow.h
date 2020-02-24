#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class home : public QMainWindow
{
    Q_OBJECT

public:
    home(QWidget *parent = nullptr);
    ~home();
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

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
