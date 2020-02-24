#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class home; }
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

private:
    Ui::home *ui;
};
#endif // MAINWINDOW_H
