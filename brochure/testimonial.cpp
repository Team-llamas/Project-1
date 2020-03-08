#include "testimonial.h"
#include "ui_testimonial.h"

Testimonial::Testimonial(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Testimonial)
{
    ui->setupUi(this);
}

Testimonial::~Testimonial()
{
    delete ui;
}
