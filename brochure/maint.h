#ifndef MAINT_H
#define MAINT_H

#include <QDialog>

namespace Ui {
class maint;
}

class maint : public QDialog
{
    Q_OBJECT

public:
    explicit maint(QWidget *parent = nullptr);
    ~maint();

private:
    Ui::maint *ui;
};

#endif // MAINT_H
