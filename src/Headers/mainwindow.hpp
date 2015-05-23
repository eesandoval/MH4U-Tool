#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include "damagecalculatorwindow.hpp"
#include "defensecalculatorwindow.hpp"
#include "teostratimerwindow.hpp"

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

    void on_teostra_timer_button_clicked();

private:
    Ui::MainWindow *ui;
    damagecalculatorwindow *damageCalculatorWindow;
    defensecalculatorwindow *defenseCalculatorWindow;
    teostratimerwindow *teostra_timer_window;
};

#endif // MAINWINDOW_HPP
