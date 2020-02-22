#ifndef INFORWINDOW_H
#define INFORWINDOW_H

#include <QWidget>

namespace Ui {
class InforWindow;
}

class InforWindow : public QWidget
{
    Q_OBJECT

public:
    explicit InforWindow(QWidget *parent = 0);
    ~InforWindow();

private:
    Ui::InforWindow *ui;
};

#endif // INFORWINDOW_H
