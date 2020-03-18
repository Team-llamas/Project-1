#include "inforwindow.h"
#include "ui_inforwindow.h"

InforWindow::InforWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InforWindow)
{
    ui->setupUi(this);
}

InforWindow::~InforWindow()
{
    delete ui;
}
