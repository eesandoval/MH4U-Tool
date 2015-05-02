#ifndef DAMAGECALCULATORWINDOW_HPP
#define DAMAGECALCULATORWINDOW_HPP

#include <QMainWindow>
#include <QString>
#include <vector>
#include <iostream>
#include "damagecalculator.hpp"
#include "querytools.hpp"

namespace Ui {
class damagecalculatorwindow;
}

class damagecalculatorwindow : public QMainWindow
{
    Q_OBJECT

private slots:
    void on_weapon_type_list_widget_clicked(const QModelIndex &index);

    void on_weapon_list_widget_clicked(const QModelIndex &index);

    void on_HHNoneRadioButton_clicked();

    void on_attackUpSRadioButton_clicked();

    void on_attackUpLRadioButton_clicked();

    void on_caclulatePushButton_clicked();

    void on_affinityUpCheckBox_clicked();

    void on_elementUpCheckBox_clicked();

    void on_motionValueListWidget_clicked(const QModelIndex &index);

public:
    explicit damagecalculatorwindow(QWidget *parent = 0);
    ~damagecalculatorwindow();

private:
    Ui::damagecalculatorwindow *ui;
    QString weapon;
    QString weaponType;
    QString motionValue;
    int *motionValues;
    int numAttacks;
};

#endif // DAMAGECALCULATORWINDOW_HPP
