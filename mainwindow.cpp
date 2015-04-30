#include "mainwindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_damage_calculator_button_clicked()
{
    damageCalculatorWindow = new damagecalculatorwindow(this);
    damageCalculatorWindow->show();
}

