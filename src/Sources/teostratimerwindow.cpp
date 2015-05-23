#include "src/Headers/teostratimerwindow.hpp"
#include "ui_teostratimerwindow.h"

teostratimerwindow::teostratimerwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::teostratimerwindow)
{
    ui->setupUi(this);

    counting = false;
    counter = 100;

    ui->warning_input->setRange(0, 99);
    ui->warning_input->setValue(20);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(timer_handler()));
}

teostratimerwindow::~teostratimerwindow()
{
    delete timer;
    delete ui;
}

void teostratimerwindow::timer_handler()
{
    --this->counter;
    QString temp = QString::number(this->counter);
    ui->time_left_number->setText(temp);
    if (this->counter == ui->warning_input->value())
    {
        ui->warning_text->setText("Get Away!");
    }
    if (this->counter <= 0)
    {
        ui->warning_text->setText("Nova!");
        timer->stop();
    }
}

void teostratimerwindow::on_start_timer_clicked()
{
    if (counting)
    {
        ui->warning_text->setText("");
        if (timer->isActive())
            timer->stop();
        counting = false;
        ui->start_timer->setText("Start\nTimer");
        ui->time_left_number->setText("100");
    }
    else
    {
        this->counter = 100;
        counting = true;
        ui->start_timer->setText("Reset\nTimer");
        timer->start(1000);
    }
}
