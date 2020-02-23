#ifndef CAPABILITY_H
#define CAPABILITY_H

#include <QDialog>

namespace Ui {
class capability;
}

class capability : public QDialog
{
    Q_OBJECT

public:
    explicit capability(QWidget *parent = nullptr);
    ~capability();

private slots:
    void on_home_clicked();

private:
    Ui::capability *ui;
};

#endif // CAPABILITY_H
