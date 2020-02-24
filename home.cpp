#include "home.h"
#include "capability.h"
#include "testimonial.h"
#include "ui_home.h"

home::home(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

home::~home()
{
    delete ui;
}


void home::on_capability_clicked()
{
    capability wind;
    wind.setModal(true);
    hide();
    wind.exec();
    show();
}

void home::on_testimonial_clicked()
{
    Testimonial wind;
    wind.setModal(true);
    hide();
    wind.exec();
    show();
}
