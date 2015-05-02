#include "damagecalculatorwindow.hpp"
#include "ui_damagecalculatorwindow.h"

damagecalculatorwindow::damagecalculatorwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::damagecalculatorwindow)
{
    ui->setupUi(this);

    motionValues = new int[20];

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
    ui->weaponSpecificNoneRadioButton->setChecked(true);
    ui->artilleryNoneRadioButton->setChecked(true);

    // Set up the spin boxes
    ui->rawHitzoneSpinBox->setMaximum(200);
    ui->rawHitzoneSpinBox->setMinimum(0);
    ui->eleHitzoneSpinBox->setMaximum(200);
    ui->eleHitzoneSpinBox->setMinimum(0);

    // When HHNoneRadioButton is checked, replayCheckBox is disabled
    ui->replayCheckBox->setDisabled(true);

    // To prevent errors, set defaults (each list widget to default row 0)
    ui->weapon_type_list_widget->setCurrentRow(0);
    on_weapon_type_list_widget_clicked(ui->weapon_type_list_widget->currentIndex());

    ui->weapon_list_widget->setCurrentRow(0);
    on_weapon_list_widget_clicked(ui->weapon_list_widget->currentIndex());

    ui->motionValueListWidget->setCurrentRow(0);
    on_motionValueListWidget_clicked(ui->motionValueListWidget->currentIndex());

    // This can be changed: default values
    // People seem to usually run these checked boxes
    ui->sharpnessCheckBox->setChecked(true);
    ui->AuLKitchenRadioButton->setChecked(true);
    ui->powerCharmCheckBox->setChecked(true);
    ui->powerTalonCheckBox->setChecked(true);
    ui->rawHitzoneSpinBox->setValue(45);
    ui->eleHitzoneSpinBox->setValue(30);

    // Set the tab names on damageTabWidget
    ui->damageTabWidget->setTabText(0, "Basic Overview");
    ui->damageTabWidget->setTabText(1, "View Details");

    // These checkboxes are not yet available
    ui->addWeaponPushButton->setDisabled(true);

}

damagecalculatorwindow::~damagecalculatorwindow()
{
    delete ui;
    delete this->motionValues;
}

void damagecalculatorwindow::on_weapon_type_list_widget_clicked(const QModelIndex &index)
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

void damagecalculatorwindow::on_weapon_list_widget_clicked(const QModelIndex &index)
{
    this->weapon = index.data(Qt::DisplayRole).toString();
}

void damagecalculatorwindow::on_HHNoneRadioButton_clicked()
{
    if (!ui->attackUpSRadioButton->isChecked() && !ui->attackUpLRadioButton->isChecked() &&
            !ui->elementUpCheckBox->isChecked() && !ui->affinityUpCheckBox->isChecked())
        ui->replayCheckBox->setDisabled(true);
}

void damagecalculatorwindow::on_attackUpSRadioButton_clicked()
{
    ui->replayCheckBox->setDisabled(false);
    if (!ui->attackUpSRadioButton->isChecked() && !ui->attackUpLRadioButton->isChecked() &&
            !ui->elementUpCheckBox->isChecked() && !ui->affinityUpCheckBox->isChecked())
        ui->replayCheckBox->setDisabled(true);
}

void damagecalculatorwindow::on_attackUpLRadioButton_clicked()
{
    ui->replayCheckBox->setDisabled(false);
    if (!ui->attackUpSRadioButton->isChecked() && !ui->attackUpLRadioButton->isChecked() &&
            !ui->elementUpCheckBox->isChecked() && !ui->affinityUpCheckBox->isChecked())
        ui->replayCheckBox->setDisabled(true);
}

void damagecalculatorwindow::on_affinityUpCheckBox_clicked()
{
    ui->replayCheckBox->setDisabled(false);
    if (!ui->attackUpSRadioButton->isChecked() && !ui->attackUpLRadioButton->isChecked() &&
            !ui->elementUpCheckBox->isChecked() && !ui->affinityUpCheckBox->isChecked())
        ui->replayCheckBox->setDisabled(true);
}

void damagecalculatorwindow::on_elementUpCheckBox_clicked()
{
    ui->replayCheckBox->setDisabled(false);
    if (!ui->attackUpSRadioButton->isChecked() && !ui->attackUpLRadioButton->isChecked() &&
            !ui->elementUpCheckBox->isChecked() && !ui->affinityUpCheckBox->isChecked())
        ui->replayCheckBox->setDisabled(true);
}

void damagecalculatorwindow::on_caclulatePushButton_clicked()
{
    std::map<std::string, std::map<std::string, float> > allModifiers;
    std::map<std::string, float> rawModifiers;
    std::map<std::string, float> eleModifiers;
    std::map<std::string, float> affinityModifiers;
    QSqlQuery query;
    QString sharpness;
    QString temp;
    float raw = 0;
    float ele = 0;
    float total = 0;
    float rawHitzone;
    float eleHitzone;
    bool artillery;

    // The following gets messy...
    // Need to get sharpness
    if (ui->sharpnessCheckBox->isChecked())
        query = findQuery("sharpness+1", this->weaponType, "name", this->weapon);
    else
        query = findQuery("sharpness", this->weaponType, "name", this->weapon);
    sharpness = query.value(0).toString();

    // Need to get all raw modifiers
    query = findQuery("attack", this->weaponType, "name", this->weapon);
    rawModifiers["attack"] = query.value(0).toString().toFloat();

    // First the weapon specific
    if (ui->CoBRadioButton->isChecked())
        rawModifiers["weaponSpecific"] = 1.05;
    else if (ui->critDistanceRadioButton->isChecked())
        rawModifiers["weaponSpecific"] = 1.50;
    else if (ui->boostModeRadioButton->isChecked())
    {
        if (this->motionValue.contains("Axe"))
            rawModifiers["weaponSpecific"] = 1.20;
        else
            rawModifiers["weaponSpecific"] = 1;
    }
    else if (ui->demonModeRadioButton->isChecked())
        rawModifiers["weaponSpecific"] = 1.15;
    else if (ui->tripleUpRadioButton->isChecked())
        rawModifiers["weaponSpecific"] = 1.25;
    else
        rawModifiers["weaponSpecific"] = 1;

    // Check if they honed for attack
    if (ui->rawHoneCheckBox->isChecked())
        rawModifiers["hone"] = 20;
    else
        rawModifiers["hone"] = 0;

    // Check if the motion value can have artillery applied to it
    if (!ui->artilleryNoneRadioButton->isChecked())
    {
        if (this->weaponType == "ChargeBlades")
        {
            if (this->motionValue.contains("Discharge") || (this->motionValue.contains("AED") &&
                                                            !this->motionValue.contains("Phials Empty")))
                artillery = true;
        }
        else if (this->weaponType == "Gunlances")
        {
            if (this->motionValue.contains("Burst"))
                artillery = true;
        }
    }
    // If artillery is true, add it to the modifier
    if (artillery)
    {
        if (ui->artilleryNoviceRadioButton->isChecked())
            rawModifiers["artillery"] = 1.1;
        else if (ui->artilleryExpertRadioButton->isChecked())
            rawModifiers["artillery"] = 1.2;
        else if (ui->artilleryGodRadioButton->isChecked())
            rawModifiers["artillery"] = 1.3;
    }
    else
        rawModifiers["artillery"] = 1;

    // Figure out which Attack up skill
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

    // If they activated their wystone for attack, apply it
    if (ui->wyvernStoneRawCheckBox->isChecked())
        rawModifiers["wystone"] = 1.20;
    else
        rawModifiers["wystone"] = 1;

    // Need to get all element modifiers
    query = findQuery("special attack", this->weaponType, "name", this->weapon);
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

    // Check if they activated their wyvern stone for element
    if (ui->wyvernStoneEleCheckBox->isChecked())
        eleModifiers["wystone"] = 1.20;
    else
        eleModifiers["wystone"] = 1;

    // Need to get all affinity modifiers
    query = findQuery("affinity", this->weaponType, "name", this->weapon);
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

    // Get the hitzone values
    rawHitzone = ui->rawHitzoneSpinBox->value();
    eleHitzone = ui->eleHitzoneSpinBox->value();

    rawHitzone = rawHitzone/100;
    eleHitzone = eleHitzone/100;

    // Now to get the motion values from the database, and finally perform calculations
    for (int i = 0; i < this->numAttacks; ++i)
    {
        raw += calculate_raw_damage(ui->weaknessExploitCheckBox->isChecked(),
                                    sharpness.toStdString(), this->weaponType.toStdString(),
                                    rawHitzone, this->motionValues[i], allModifiers);
        ele += calculate_ele_damage(sharpness.toStdString(), allModifiers, eleHitzone,
                                    ui->criticalElementCheckBox->isChecked());
    }

    total = raw + ele;

    // Set the text labels
    temp = QString::number(raw, 'g', 5);
    ui->rawDamageFloatLabel->setText(temp);

    temp = QString::number(ele, 'g', 5);
    ui->eleDamageFloatLabel->setText(temp);

    temp = QString::number(total, 'g', 5);
    ui->totalDamageFloatLabel->setText(temp);

    temp = QString::number(raw/this->numAttacks, 'g', 5);
    ui->averageRawDamagePerLabel->setText(temp);

    temp = QString::number(ele/this->numAttacks, 'g', 5);
    ui->averageEleDamagePerLabel->setText(temp);

    temp = QString::number(total/this->numAttacks, 'g', 5);
    ui->averageTotalNumberPerLabel->setText(temp);

    temp = QString::number(this->numAttacks);
    ui->numAttacksLabel->setText(temp);

    ui->motionValueNameLabel->setText(this->motionValue);
}

void damagecalculatorwindow::on_motionValueListWidget_clicked(const QModelIndex &index)
{
    QString temp, temp2;
    QSqlQuery query;
    int leftoff = 1;

    this->motionValue = index.data().toString();

    query = findQuery("number of attacks", "MotionValues", "name",
                      this->motionValue, "weapon type", this->weaponType);
    this->numAttacks = query.value(0).toInt();

    query = findQuery("motion value text", "MotionValues", "name",
                      this->motionValue, "weapon type", this->weaponType);
    temp = query.value(0).toString();

    for (int i = 0; i < this->numAttacks; ++i)
    {
        temp2 = "";
        for (int j = leftoff; temp.at(j) != ',' && temp.at(j) != ']'; ++j, ++leftoff)
            temp2.append(temp.at(j));
        ++(++leftoff);
        motionValues[i] = temp2.toInt();
    }

    ui->motionValueStringLabel->setText(query.value(0).toString());
}
