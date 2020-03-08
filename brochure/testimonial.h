#ifndef TESTIMONIAL_H
#define TESTIMONIAL_H

#include <QDialog>

namespace Ui {
class Testimonial;
}

class Testimonial : public QDialog
{
    Q_OBJECT

public:
    explicit Testimonial(QWidget *parent = nullptr);
    ~Testimonial();

private:
    Ui::Testimonial *ui;
};

#endif // TESTIMONIAL_H
