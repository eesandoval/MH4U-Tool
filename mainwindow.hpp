#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include "damagecalculatorwindow.hpp"

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

private:
    Ui::MainWindow *ui;
    damagecalculatorwindow *damageCalculatorWindow;
};

#endif // MAINWINDOW_HPP
