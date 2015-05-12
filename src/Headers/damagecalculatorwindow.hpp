#ifndef DAMAGECALCULATORWINDOW_HPP
#define DAMAGECALCULATORWINDOW_HPP

#include <QMainWindow>
#include <QString>
#include <fstream>
#include <vector>
#include "weapon.hpp"
#include "damagecalculator.hpp"
#include "querytools.hpp"
#include "addweapondialog.hpp"

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

    void on_weapon_type_list_widget_activated(const QModelIndex &index);

    void on_weapon_list_widget_activated(const QModelIndex &index);

    void on_motionValueListWidget_activated(const QModelIndex &index);

    void on_addWeaponPushButton_clicked();

    void updateCustomWeaponsListWidget();

    void updateChosenWeapon();

    void on_customWeaponsListWidget_clicked(const QModelIndex &index);

public:
    explicit damagecalculatorwindow(QWidget *parent = 0);
    ~damagecalculatorwindow();

private:
    Ui::damagecalculatorwindow *ui;
    addweapondialog *addWeaponDialog;
    QString weaponName;
    QString weaponType;
    QString motionValue;
    int *motionValues;
    int numAttacks;
    bool customWeapon;
    std::vector<weapon> customWeapons;
    weapon chosenWeapon;
};

#endif // DAMAGECALCULATORWINDOW_HPP
