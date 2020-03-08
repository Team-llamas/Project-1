#include "home.h"
#include "capability.h"
#include "testimonial.h"
#include "ui_home.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_capability_clicked()
{
    capability wind;
    wind.setModal(true);
    hide();
    wind.exec();
    show();
}

void MainWindow::on_testimonial_clicked()
{
    Testimonial wind;
    wind.setModal(true);
    hide();
    wind.exec();
    show();
}
