#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include "damagecalculatorwindow.hpp"
#include "defensecalculatorwindow.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_damage_calculator_button_clicked();

    void on_damage_calculator_button_2_clicked();

private:
    Ui::MainWindow *ui;
    damagecalculatorwindow *damageCalculatorWindow;
    defensecalculatorwindow *defenseCalculatorWindow;
};

#endif // MAINWINDOW_HPP
