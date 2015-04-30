#include <iostream>
#include "damagecalculatordialog.hpp"
#include "ui_damagecalculatordialog.h"
#include "damagecalculator.hpp"

damagecalculatordialog::damagecalculatordialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::damagecalculatordialog)
{
    ui->setupUi(this);

    // Set up the "None" radio buttons
    ui->AuXNoneRadioButton->setChecked(true);
    ui->CENoneRadioButton->setChecked(true);
    ui->gloveNoneRadioButton->setChecked(true);
    ui->elementNoneRadioButton->setChecked(true);
    ui->HHNoneRadioButton->setChecked(true);
    ui->dangerNoneRadioButton->setChecked(true);
    ui->kitchenNoneRadioButton->setChecked(true);
    ui->mightNoneRadioButton->setChecked(true);
    ui->fortifyNoneRadioButton->setChecked(true);

    // When HHNoneRadioButton is checked, replayCheckBox is disabled
    ui->replayCheckBox->setDisabled(true);

    // To prevent errors, set defaults (each list widget to default row 0)
    ui->weapon_type_list_widget->setCurrentRow(0);
    on_weapon_type_list_widget_clicked(ui->weapon_type_list_widget->currentIndex());

    ui->weapon_list_widget->setCurrentRow(0);
    on_weapon_list_widget_clicked(ui->weapon_list_widget->currentIndex());

    ui->motionValueListWidget->setCurrentRow(0);
    on_motionValueListWidget_clicked(ui->motionValueListWidget->currentIndex());
}

damagecalculatordialog::~damagecalculatordialog()
{
    delete ui;
}

QSqlQuery runQuery(const QString& sql)
{
    QSqlQuery query(sql);
    query.exec();
    return query;
}


QSqlQuery damagecalculatordialog::createAndRunSpecificQuery(const QString& selectSQL)
{
    QString sql = "SELECT \"";
    QSqlQuery result;

    sql.append(selectSQL);
    sql.append("\" FROM ");
    sql.append(this->weaponType);
    sql.append(" WHERE name=\"");
    sql.append(this->weapon);
    sql.append("\"");
    result = runQuery(sql);
    result.next();

    return result;
}

void damagecalculatordialog::on_weapon_type_list_widget_clicked(const QModelIndex &index)
{
    QSqlQuery query;
    QString sql = "SELECT name FROM ";

    // Find out if the weapon_list_widget is empty, and if not empty it
    if (ui->weapon_list_widget->count() > 0)
        ui->weapon_list_widget->clear();

    // Find out if motionValueListWidget is empty, and if not empty it
    if (ui->motionValueListWidget->count() > 0)
        ui->motionValueListWidget->clear();

    // Update the contents of the weapon_list_widget
    this->weaponType = index.data(Qt::DisplayRole).toString();
    sql.append(this->weaponType);
    query = runQuery(sql);
    while(query.next())
        ui->weapon_list_widget->addItem(query.value(0).toString());

    // Update the contents of the motionValueListWidget
    sql = "SELECT name FROM MotionValues WHERE \"weapon type\"=\"";
    sql.append(this->weaponType);
    sql.append("\"");
    query = runQuery(sql);
    while(query.next())
        ui->motionValueListWidget->addItem(query.value(0).toString());

    // To prevent errors, set defaults (each list widget to default row 0)
    ui->weapon_list_widget->setCurrentRow(0);
    on_weapon_list_widget_clicked(ui->weapon_list_widget->currentIndex());

    ui->motionValueListWidget->setCurrentRow(0);
    on_motionValueListWidget_clicked(ui->motionValueListWidget->currentIndex());
}

void damagecalculatordialog::on_weapon_list_widget_clicked(const QModelIndex &index)
{
    this->weapon = index.data(Qt::DisplayRole).toString();
}

void damagecalculatordialog::on_HHNoneRadioButton_clicked()
{
    if (!ui->attackUpSRadioButton->isChecked() && !ui->attackUpLRadioButton->isChecked() &&
            !ui->elementUpCheckBox->isChecked() && !ui->affinityUpCheckBox->isChecked())
        ui->replayCheckBox->setDisabled(true);
}

void damagecalculatordialog::on_attackUpSRadioButton_clicked()
{
    ui->replayCheckBox->setDisabled(false);
    if (!ui->attackUpSRadioButton->isChecked() && !ui->attackUpLRadioButton->isChecked() &&
            !ui->elementUpCheckBox->isChecked() && !ui->affinityUpCheckBox->isChecked())
        ui->replayCheckBox->setDisabled(true);
}

void damagecalculatordialog::on_attackUpLRadioButton_clicked()
{
    ui->replayCheckBox->setDisabled(false);
    if (!ui->attackUpSRadioButton->isChecked() && !ui->attackUpLRadioButton->isChecked() &&
            !ui->elementUpCheckBox->isChecked() && !ui->affinityUpCheckBox->isChecked())
        ui->replayCheckBox->setDisabled(true);
}

void damagecalculatordialog::on_affinityUpCheckBox_clicked()
{
    ui->replayCheckBox->setDisabled(false);
    if (!ui->attackUpSRadioButton->isChecked() && !ui->attackUpLRadioButton->isChecked() &&
            !ui->elementUpCheckBox->isChecked() && !ui->affinityUpCheckBox->isChecked())
        ui->replayCheckBox->setDisabled(true);
}

void damagecalculatordialog::on_elementUpCheckBox_clicked()
{
    ui->replayCheckBox->setDisabled(false);
    if (!ui->attackUpSRadioButton->isChecked() && !ui->attackUpLRadioButton->isChecked() &&
            !ui->elementUpCheckBox->isChecked() && !ui->affinityUpCheckBox->isChecked())
        ui->replayCheckBox->setDisabled(true);
}

void damagecalculatordialog::on_caclulatePushButton_clicked()
{
    std::map<std::string, std::map<std::string, float> > allModifiers;
    std::map<std::string, float> rawModifiers;
    std::map<std::string, float> eleModifiers;
    std::map<std::string, float> affinityModifiers;
    QSqlQuery query;
    QString sharpness;
    QString temp;
    int motionValue;

    // The following gets messy...
    // Need to get sharpness
    if (ui->sharpnessCheckBox->isChecked())
        query = createAndRunSpecificQuery("sharpness+1");
    else
        query = createAndRunSpecificQuery("sharpness");
    sharpness = query.value(0).toString();

    // Need to get all raw modifiers
    query = createAndRunSpecificQuery("attack");
    rawModifiers["attack"] = query.value(0).toString().toFloat();

    if (ui->AuSRadioButton->isChecked())
        rawModifiers["AuX"] = 10;
    else if (ui->AuMRadioButton->isChecked())
        rawModifiers["AuX"] = 15;
    else if (ui->AuLRadioButton->isChecked())
        rawModifiers["AuX"] = 20;
    else if (ui->AuXLRadioButton->isChecked())
        rawModifiers["AuX"] = 25;
    else
        rawModifiers["AuX"] = 0;

    if (ui->AuSKitchenRadioButton->isChecked())
        rawModifiers["kitchen"] = 5;
    else if (ui->AuLKitchenRadioButton->isChecked())
        rawModifiers["kitchen"] = 7;
    else
        rawModifiers["kitchen"] = 0;

    if (ui->mightPillRadioButton->isChecked())
        rawModifiers["seed"] = 25;
    else if (ui->mightSeedRadioButton->isChecked())
        rawModifiers["seed"] = 10;
    else
        rawModifiers["seed"] = 0;

    if (ui->challenger1RadioButton->isChecked())
        rawModifiers["glove"] = 10;
    else if (ui->challenger2RadioButton->isChecked())
        rawModifiers["glove"] = 25;
    else if (ui->peakPerformanceRadioButton->isChecked())
        rawModifiers["glove"] = 20;
    else
        rawModifiers["glove"] = 0;

    if (ui->powerCharmCheckBox->isChecked())
        rawModifiers["powerCharm"] = 6;
    else
        rawModifiers["powerCharm"] = 0;

    if (ui->powerTalonCheckBox->isChecked())
        rawModifiers["powerTalon"] = 9;
    else
        rawModifiers["powerTalon"] = 0;

    if (ui->attackUpSRadioButton->isChecked())
        rawModifiers["HH"] = 1.10;
    else if (ui->attackUpLRadioButton->isChecked())
        rawModifiers["HH"] = 1.15;
    else
        rawModifiers["HH"] = 1;

    if (ui->replayCheckBox->isChecked() && ui->replayCheckBox->isEnabled())
        rawModifiers["replay"] = 0.05;
    else
        rawModifiers["replay"] = 0;

    if (ui->adrenaline2RadioButton->isChecked())
        rawModifiers["danger"] = 1.30;
    else if (ui->heroicsRadioButton->isChecked())
        rawModifiers["danger"] = 1.35;
    else
        rawModifiers["danger"] = 1;

    if (ui->faint1RadioButton->isChecked())
        rawModifiers["fortify"] = 1.1;
    else if (ui->faint2RadioButton->isChecked())
        rawModifiers["fortify"] = 1.2;
    else
        rawModifiers["fortify"] = 1;

    // Need to get all element modifiers
    query = createAndRunSpecificQuery("special attack");
    eleModifiers["specialAttack"] = query.value(0).toString().toFloat();

    if (ui->element1RadioButton->isChecked())
    {
        eleModifiers["elementAdd"] = 40;
        eleModifiers["elementMul"] =  1.05;
    }
    else if (ui->element2RadioButton->isChecked())
    {
        eleModifiers["elementAdd"] = 60;
        eleModifiers["elementMul"] = 1.10;
    }
    else if (ui->element3RadioButton->isChecked())
    {
        eleModifiers["elementAdd"] = 90;
        eleModifiers["elementMul"] = 1.15;
    }
    else
    {
        eleModifiers["elementAdd"] = 0;
        eleModifiers["elementMul"] = 1;
    }

    if (ui->elementAtkUpCheckBox->isChecked())
        eleModifiers["elementAtkUp"] = 1.1;
    else
        eleModifiers["elementAtkUp"] = 1;

    if (ui->elementUpCheckBox->isChecked())
        eleModifiers["elementUp"] = 1.1;
    else
        eleModifiers["elementUp"] = 1;

    if (ui->replayCheckBox->isChecked() && ui->replayCheckBox->isEnabled())
        eleModifiers["replay"] = 0.05;
    else
        eleModifiers["replay"] = 0;


    // Need to get all affinity modifiers
    query = createAndRunSpecificQuery("affinity");
    affinityModifiers["affinity"] = query.value(0).toString().toFloat();

    if (ui->criticalEye1RadioButton->isChecked())
        affinityModifiers["criticalEye"] = 0.10;
    else if (ui->criticalEye2RadioButton->isChecked())
        affinityModifiers["criticalEye"] = 0.15;
    else if (ui->criticalEye3RadioButton->isChecked())
        affinityModifiers["criticalEye"] = 0.20;
    else if (ui->criticalGodRadioButton->isChecked())
        affinityModifiers["criticalEye"] = 0.30;
    else
        affinityModifiers["criticalEye"] = 0;

    if (ui->latentPower1RadioButton->isChecked())
        affinityModifiers["glove"] = 0.30;
    else if (ui->latentPower2RadioButton->isChecked())
        affinityModifiers["glove"] = 0.50;
    else if (ui->challenger1RadioButton->isChecked())
        affinityModifiers["glove"] = 0.10;
    else if (ui->challenger2RadioButton->isChecked())
        affinityModifiers["glove"] = 0.20;
    else
        affinityModifiers["glove"] = 0;

    if (ui->criticalDrawCheckBox->isChecked())
        affinityModifiers["criticalDraw"] = 1;
    else
        affinityModifiers["criticalDraw"] = 0;

    if (ui->affinityUpCheckBox->isChecked())
        affinityModifiers["affinityUp"] = 0.3;
    else
        affinityModifiers["affinityUp"] = 0;

    if (ui->replayCheckBox->isChecked() && ui->replayCheckBox->isEnabled())
        affinityModifiers["replay"] = 0.05;
    else
        affinityModifiers["replay"] = 0;

    allModifiers["rawModifiers"] = rawModifiers;
    allModifiers["affinityModifiers"] = affinityModifiers;
    allModifiers["eleModifiers"] = eleModifiers;

    temp = "SELECT \"motion value\" FROM MotionValues WHERE \"weapon type\"=\"";
    temp.append(this->weaponType);
    temp.append("\" AND name=\"");
    temp.append(this->motionValue);
    temp.append("\"");
    query = runQuery(temp);
    query.next();
    motionValue = query.value(0).toInt();

    float raw = calculate_raw_damage(ui->weaknessExploitCheckBox->isChecked(),
                                     sharpness.toStdString(), this->weaponType.toStdString(),
                                     0.45, motionValue, allModifiers);
    float ele = calculate_ele_damage(sharpness.toStdString(), allModifiers, 0.3);
    float total = raw + ele;

    temp = QString::number(raw, 'g', 4);
    ui->rawDamageFloatLabel->setText(temp);

    temp = QString::number(ele, 'g', 4);
    ui->eleDamageFloatLabel->setText(temp);

    temp = QString::number(total, 'g', 4);
    ui->totalDamageFloatLabel->setText(temp);
}

void damagecalculatordialog::on_motionValueListWidget_clicked(const QModelIndex &index)
{
    QString sql;
    QSqlQuery query;

    this->motionValue = index.data().toString();

    sql = "SELECT \"motion value text\" FROM MotionValues WHERE \"name\"=\"";
    sql.append(this->motionValue);
    sql.append("\" AND \"weapon type\"=\"");
    sql.append(this->weaponType);
    sql.append("\"");
    query = runQuery(sql);
    query.next();

    ui->motionValueStringLabel->setText(query.value(0).toString());
}
