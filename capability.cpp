#include "capability.h"
#include "mainwindow.h"
#include "ui_capability.h"

capability::capability(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::capability)
{
    ui->setupUi(this);
}

capability::~capability()
{
    delete ui;
}

void capability::on_home_clicked()
{
    this->done(0);
}
