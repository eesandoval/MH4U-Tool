#include "src/Headers/defensecalculatorwindow.hpp"
#include "ui_defensecalculatorwindow.h"

defensecalculatorwindow::defensecalculatorwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::defensecalculatorwindow)
{
    ui->setupUi(this);

    // Set the range for the armor pieces from 0 to MAX_ARMOR_DEF (150)
    // MAX_ARMOR_DEF is defined under the header file
    ui->armor_helmet->setRange(0, MAX_ARMOR_DEF);
    ui->armor_torso->setRange(0, MAX_ARMOR_DEF);
    ui->armor_gloves->setRange(0, MAX_ARMOR_DEF);
    ui->armor_waist->setRange(0, MAX_ARMOR_DEF);
    ui->armor_boots->setRange(0, MAX_ARMOR_DEF);

    // Set the default radio button states to None
    ui->defense_up_skill_none->setChecked(true);
    ui->defense_up_kitchen_none->setChecked(true);
    ui->hunting_horn_none->setChecked(true);
    ui->fortify_none->setChecked(true);

    // Set defaults
    this->total_defense = 0;
    this->helmet = 0;
    this->torso = 0;
    this->gloves = 0;
    this->waist = 0;
    this->boots = 0;
    this->defense_skill_add = 0;
    this->defense_skill_mult = 1;
    this->hunting_horn_mult = 1;
    this->kitchen_add = 0;
    this->fortify_mult = 1;
}

defensecalculatorwindow::~defensecalculatorwindow()
{
    delete ui;
}

void defensecalculatorwindow::on_calculate_push_button_clicked()
{
    // TODO
}

void defensecalculatorwindow::update_total_defense()
{
    /*
     * This function updates the total_defense
     * It first adds all additions (each armor piece, the defense skill addition)
     * It then uses the multipliers to further update the tota_defense
    */
    this->total_defense = this->helmet + this->torso + this->gloves + this->waist + this->boots;
    this->total_defense += this->defense_skill_add;
    this->total_defense += this->kitchen_add;

    this->total_defense *= this->defense_skill_mult;
    this->total_defense *= this->hunting_horn_mult;
    this->total_defense *= this->fortify_mult;
}

void defensecalculatorwindow::change_displayed_defense()
{
    /*
     * This function updates the displayed defense using the
     * total_defense by converting it to a QString (temp) and setting the
     * text label for total_defense_display in the UI
    */
    QString temp;
    temp = QString::number(this->total_defense);
    ui->total_defense_display->setText(temp);
}

/*
 * The following are specific to the armor piece
 * Each function will subtract the previous value from total defense,
 * add the new value, and set the previous value to the new value
 * After that, each will update the total defense and display it
*/
void defensecalculatorwindow::on_armor_helmet_valueChanged(int arg1)
{
    this->total_defense = this->total_defense - this->helmet + arg1;
    this->helmet = arg1;
    update_total_defense();
    change_displayed_defense();
}

void defensecalculatorwindow::on_armor_torso_valueChanged(int arg1)
{
    this->total_defense = this->total_defense - this->torso + arg1;
    this->torso = arg1;
    update_total_defense();
    change_displayed_defense();
}

void defensecalculatorwindow::on_armor_gloves_valueChanged(int arg1)
{
    this->total_defense = this->total_defense - this->gloves + arg1;
    this->gloves = arg1;
    update_total_defense();
    change_displayed_defense();
}

void defensecalculatorwindow::on_armor_waist_valueChanged(int arg1)
{
    this->total_defense = this->total_defense - this->waist + arg1;
    this->waist = arg1;
    update_total_defense();
    change_displayed_defense();
}

void defensecalculatorwindow::on_armor_boots_valueChanged(int arg1)
{
    this->total_defense = this->total_defense - this->boots + arg1;
    this->boots = arg1;
    update_total_defense();
    change_displayed_defense();
}

/*
 * These next functions calculate the bonus from the defense up skill
 * If its toggled, add the bonus and if the button is untoggled detract the bonus
 * Defense up skill has two bonuses: an addition and a multiplier stored under
 * defense_skill_add and defense_skill_mult respectively
 * Each function will update the total defense and display it
*/
void defensecalculatorwindow::on_defense_up_skill_small_toggled(bool checked)
{
    // The small bonus is multiplier 1 and addition 15;
    if (checked)
    {
        this->defense_skill_add = 15;
        this->defense_skill_mult = 1;
    }
    else
    {
        this->defense_skill_add = 0;
        this->defense_skill_mult = 1;
    }
    update_total_defense();
    change_displayed_defense();
}

void defensecalculatorwindow::on_defense_up_skill_medium_toggled(bool checked)
{
    // The medium bonus is multiplier 1.03 and addition 20;
    if (checked)
    {
        this->defense_skill_add = 20;
        this->defense_skill_mult = 1.03;
    }
    else
    {
        this->defense_skill_add = 0;
        this->defense_skill_mult = 1;
    }
    update_total_defense();
    change_displayed_defense();
}

void defensecalculatorwindow::on_defense_up_skill_large_toggled(bool checked)
{
    // The medium bonus is multiplier 1.05 and addition 25;
    if (checked)
    {
        this->defense_skill_add = 25;
        this->defense_skill_mult = 1.05;
    }
    else
    {
        this->defense_skill_add = 0;
        this->defense_skill_mult = 1;
    }
    update_total_defense();
    change_displayed_defense();
}

void defensecalculatorwindow::on_defense_up_skill_extra_large_toggled(bool checked)
{
    // The medium bonus is multiplier 1.08 and addition 30;
    if (checked)
    {
        this->defense_skill_add = 30;
        this->defense_skill_mult = 1.08;
    }
    else
    {
        this->defense_skill_add = 0;
        this->defense_skill_mult = 1;
    }
    update_total_defense();
    change_displayed_defense();
}

/*
 * These next functions calculate the bonus from the hunting horn
 * If its toggled, add the bonus and if the button is untoggled detract the bonus
 * The hunting horn has a multiplier that can be increased by 0.05 (see replay further below)
 * Each function will update the total defense and display it
*/
void defensecalculatorwindow::on_hunting_horn_small_toggled(bool checked)
{
    // The hunting horn small bonus is multiplier 1.10
    if (checked)
        this->hunting_horn_mult = 1.10;
    else
        this->hunting_horn_mult = 1;
    update_total_defense();
    change_displayed_defense();
}

void defensecalculatorwindow::on_hunting_horn_large_toggled(bool checked)
{
    // The hunting horn large bonus is multiplier 1.15
    if (checked)
        this->hunting_horn_mult = 1.15;
    else
        this->hunting_horn_mult = 1;
    update_total_defense();
    change_displayed_defense();
}

void defensecalculatorwindow::on_hunting_horn_replay_toggled(bool checked)
{
    /*
     * The replay adds 0.05 to the hunting horn multiplier if its toggled
     * When it is untoggled, detract that 0.05 from the hunting horn multilpier
     * The function will update the total defense and display it
    */
    // TODO: Fix when this gets checked and unchecked repeatedly
    if (checked && ui->hunting_horn_none->isChecked() == false)
        this->hunting_horn_mult += 0.05;
    else if (checked == false && ui->hunting_horn_none->isChecked() == false)
        this->hunting_horn_mult -= 0.05;
    update_total_defense();
    change_displayed_defense();
}

void defensecalculatorwindow::on_hunting_horn_none_toggled(bool checked)
{
    /*
     * A special role is given to the None radio button
     * When checked, it will disable the hunting horn replay
     * When unchecked, it will renable it
     * This is to prevent errors with the hunting horn replay check box
    */
    if (checked)
        ui->hunting_horn_replay->setEnabled(false);
    else
        ui->hunting_horn_replay->setEnabled(true);
}

/*
 * These next functions store the bonus from the kitchen in kitchen_add
 * If its toggled, add the bonus and if the button is untoggled detract the bonus
 * Each function will update the total defense and display it
*/
void defensecalculatorwindow::on_defense_up_kitchen_small_toggled(bool checked)
{
    if (checked)
        this->kitchen_add = 5;
    else
        this->kitchen_add = 0;
    update_total_defense();
    change_displayed_defense();
}

void defensecalculatorwindow::on_defense_up_kitchen_large_toggled(bool checked)
{
    if (checked)
        this->kitchen_add = 7;
    else
        this->kitchen_add = 0;
    update_total_defense();
    change_displayed_defense();
}

/*
 * These next functions store the bonus from the fortify skill in fortify_mult
 * If its toggled, add the bonus and if the button is untoggled detract the bonus
 * Each function will update the total defense and display it
*/
void defensecalculatorwindow::on_fortify_cart1_toggled(bool checked)
{
    if (checked)
        this->fortify_mult = 1.1;
    else
        this->fortify_mult = 1;
    update_total_defense();
    change_displayed_defense();
}

void defensecalculatorwindow::on_fortify_cart2_toggled(bool checked)
{
    if (checked)
        this->fortify_mult = 1.2;
    else
        this->fortify_mult = 1;
    update_total_defense();
    change_displayed_defense();
}
