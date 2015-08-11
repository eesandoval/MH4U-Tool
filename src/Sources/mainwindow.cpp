#include "src/Headers/mainwindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->defense_calculator_button->setDisabled(true);
    this->damageCalculatorWindow = new damagecalculatorwindow(this);
    this->defenseCalculatorWindow = new defensecalculatorwindow(this);
    this->teostra_timer_window = new teostratimerwindow(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete this->damageCalculatorWindow;
    delete this->defenseCalculatorWindow;
    delete this->teostra_timer_window;
}

void MainWindow::on_damage_calculator_button_clicked()
{
    damageCalculatorWindow = new damagecalculatorwindow(this);
    damageCalculatorWindow->show();
    damageCalculatorWindow->setFixedSize(damageCalculatorWindow->size());
}

void MainWindow::on_teostra_timer_button_clicked()
{
    teostra_timer_window = new teostratimerwindow(this);
    teostra_timer_window->show();
}

void MainWindow::on_defense_calculator_button_clicked()
{
    defenseCalculatorWindow = new defensecalculatorwindow(this);
    defenseCalculatorWindow->show();
}
