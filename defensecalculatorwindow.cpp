#include "defensecalculatorwindow.hpp"
#include "ui_defensecalculatorwindow.h"

defensecalculatorwindow::defensecalculatorwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::defensecalculatorwindow)
{
    ui->setupUi(this);
}

defensecalculatorwindow::~defensecalculatorwindow()
{
    delete ui;
}
