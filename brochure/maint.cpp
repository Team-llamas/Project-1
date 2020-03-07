#include "maint.h"
#include "ui_maint.h"

maint::maint(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::maint)
{
    ui->setupUi(this);
}

maint::~maint()
{
    delete ui;
}
