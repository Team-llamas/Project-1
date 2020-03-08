#include "capability.h"
#include "home.h"
#include "testimonial.h"
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

void capability::on_testimonial_clicked()
{
    Testimonial wind;
    wind.setModal(true);
    hide();
    wind.exec();
    show();
}
