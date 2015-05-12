#include "src/Headers/defensecalculatorwindow.hpp"
#include "ui_defensecalculatorwindow.h"

defensecalculatorwindow::defensecalculatorwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::defensecalculatorwindow)
{
    ui->setupUi(this);

    // Set the range for the armor pieces from 0 to MAX_ARMOR_DEF (150)
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
    this->defense_skill = 0;
    this->hunting_horn = 0;
}

defensecalculatorwindow::~defensecalculatorwindow()
{
    delete ui;
}

void defensecalculatorwindow::on_calculate_push_button_clicked()
{
    unsigned int armor_defense;
    unsigned int defense_up_skill;

    armor_defense = ui->armor_helmet->value() + ui->armor_torso->value() +
                    ui->armor_gloves->value() + ui->armor_waist->value() +
                    ui->armor_boots->value();

    if (ui->defense_up_skill_none)
        defense_up_skill = 0;
    else if (ui->defense_up_skill_small)
        defense_up_skill = 1;
    else if (ui->defense_up_skill_medium)
        defense_up_skill = 2;
    else if (ui->defense_up_skill_large)
        defense_up_skill = 3;
    else if (ui->defense_up_skill_extra_large)
        defense_up_skill = 4;
    else
        //TODO: Implement error handler
        defense_up_skill = -1;
}

void defensecalculatorwindow::update_total_defense()
{
    // Reset the defense skill bonus and its effects
    this->total_defense -= this->defense_skill;
    this->defense_skill = 0;
    // Find out which defense skill bonus is active and redo the effects
    if (ui->defense_up_skill_small->isChecked())
        on_defense_up_skill_small_toggled(true);
    else if (ui->defense_up_skill_medium->isChecked())
        on_defense_up_skill_medium_toggled(true);
    else if (ui->defense_up_skill_large->isChecked())
        on_defense_up_skill_large_toggled(true);
    else if (ui->defense_up_skill_extra_large->isChecked())
        on_defense_up_skill_extra_large_toggled(true);

    // Reset the hunting horn skill bonus and its effects
    this->total_defense -= this->hunting_horn;
    this->hunting_horn = 0;
    // Find out which hunting horn skill bonus is active and redo the effects
    if (ui->hunting_horn_small->isChecked())
        on_hunting_horn_small_toggled(true);
    else if (ui->hunting_horn_large->isChecked())
        on_hunting_horn_large_toggled(true);
}

void defensecalculatorwindow::change_displayed_defense()
{
     QString temp;
     temp = QString::number(this->total_defense);
     ui->total_defense_display->setText(temp);
}

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

void defensecalculatorwindow::on_defense_up_skill_small_toggled(bool checked)
{
    // If its toggled, add the bonus and if it got untoggled detract the bonus
    // The small bonus is 10;
    if (checked)
    {
        this->defense_skill = 10;
        this->total_defense += this->defense_skill;
    }
    else
    {
        this->total_defense -= this->defense_skill;
        this->defense_skill = 0;
    }
    change_displayed_defense();
}

void defensecalculatorwindow::on_defense_up_skill_medium_toggled(bool checked)
{
    // If its toggled, add the bonus and if it got untoggled detract the bonus
    // The medium bonus is the defense * 0.05 + 10;
    if (checked)
    {
        this->defense_skill = this->total_defense * 0.05 + 10;
        this->total_defense += this->defense_skill;
    }
    else
    {
        this->total_defense -= this->defense_skill;
        this->defense_skill = 0;
    }
    change_displayed_defense();
}

void defensecalculatorwindow::on_defense_up_skill_large_toggled(bool checked)
{
    // If its toggled, add the bonus and if it got untoggled detract the bonus
    // The large bonus is the defense * 0.10 + 10;
    if (checked)
    {
        this->defense_skill = this->total_defense * 0.10 + 10;
        this->total_defense += this->defense_skill;
    }
    else
    {
        this->total_defense -= this->defense_skill;
        this->defense_skill = 0;
    }
    change_displayed_defense();
}

void defensecalculatorwindow::on_defense_up_skill_extra_large_toggled(bool checked)
{
    // If its toggled, add the bonus and if it got untoggled detract the bonus
    // The extra large bonus is the defense * 0.15 + 10;
    if (checked)
    {
        this->defense_skill = this->total_defense * 0.15 + 10;
        this->total_defense += this->defense_skill;
    }
    else
    {
        this->total_defense -= this->defense_skill;
        this->defense_skill = 0;
    }
    change_displayed_defense();
}

void defensecalculatorwindow::on_hunting_horn_small_toggled(bool checked)
{
    // If its toggled, add the bonus and if it got untoggled detract the bonus
    // The small hunting horn bonus is the defense * 0.10
    // If the replay is done, the bonus is instead defense * 0.15
    int temp = this->total_defense - this->defense_skill;
    if (checked)
    {
        if (ui->hunting_horn_replay->isChecked())
            this->hunting_horn = this->total_defense * 0.15;
        else
            this->hunting_horn = this->total_defense * 0.10;
        this->total_defense += this->hunting_horn;
    }
    else
    {
        this->total_defense -= this->hunting_horn;
        this->hunting_horn = 0;
    }
    change_displayed_defense();
}

void defensecalculatorwindow::on_hunting_horn_large_toggled(bool checked)
{
    // If its toggled, add the bonus and if it got untoggled detract the bonus
    // The small hunting horn bonus is the defense * 0.15
    // If the replay is done, the bonus is instead defense * 0.20
    if (checked)
    {
        if (ui->hunting_horn_replay->isChecked())
            this->hunting_horn = this->total_defense * 0.20;
        else
            this->hunting_horn = this->total_defense * 0.15;
        this->total_defense += this->hunting_horn;
    }
    else
    {
        this->total_defense -= this->hunting_horn;
        this->hunting_horn = 0;
    }
    change_displayed_defense();
}

void defensecalculatorwindow::on_hunting_horn_replay_toggled(bool checked)
{
    // TODO: Fix when this gets checked and unchecked repeatedly
    update_total_defense();
}

void defensecalculatorwindow::on_hunting_horn_none_toggled(bool checked)
{
    if (checked)
        ui->hunting_horn_replay->setEnabled(false);
    else
        ui->hunting_horn_replay->setEnabled(true);
}
