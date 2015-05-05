#include "damagecalculatorwindow.hpp"
#include "ui_damagecalculatorwindow.h"
#include <iostream>

damagecalculatorwindow::damagecalculatorwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::damagecalculatorwindow)
{
    ui->setupUi(this);

    motionValues = new int[20];
    customWeapon = false;

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

    // Update the custom weapons
    damagecalculatorwindow::updateCustomWeaponsListWidget();

}

damagecalculatorwindow::~damagecalculatorwindow()
{
    delete ui;
    delete this->motionValues;
}

void damagecalculatorwindow::updateCustomWeaponsListWidget()
{
    std::ifstream inFile;
    std::string line;
    weapon temp;
    int count = 0;

    this->customWeapons.clear();
    ui->customWeaponsListWidget->clear();

    inFile.open("MH4U-Tool-Custom-Weapons.txt");
    if (inFile.is_open())
    {
        std::cout << "We Opened!" << std::endl;
        while(std::getline(inFile, line))
        {
            switch(count++)
            {
            case 0:
                temp.name = QString::fromStdString(line);
                break;
            case 1:
                temp.weapon_type = QString::fromStdString(line);
                break;
            case 2:
                temp.attack = QString::fromStdString(line).toInt();
                break;
            case 3:
                temp.special = QString::fromStdString(line);
                break;
            case 4:
                temp.special_attack = QString::fromStdString(line).toInt();
                break;
            case 5:
                temp.affinity = QString::fromStdString(line).toFloat();
                break;
            case 6:
                temp.sharpness = QString::fromStdString(line);
                break;
            case 7:
                temp.sharpness1 = QString::fromStdString(line);
                break;
            case 8:
                count = 0;
                temp.rarity = 10;
                temp.special2 = "";
                temp.special_attack2 = 0;
                temp.num_slots = 0;
                temp.defense = 0;
                this->customWeapons.push_back(temp);
                break;
            default:
                std::cout << "Error" << std::endl;
            }
        }
        inFile.close();
    }
    for (unsigned int i = 0; i < this->customWeapons.size(); ++i)
        ui->customWeaponsListWidget->addItem(this->customWeapons[i].name);
    ui->customWeaponsListWidget->addItem("None");

    // Set it back to None
    ui->customWeaponsListWidget->setCurrentRow(this->customWeapons.size());
}

void damagecalculatorwindow::on_weapon_type_list_widget_clicked(const QModelIndex &index)
{
    QSqlQuery query;
    QString sql = "SELECT name FROM ";

    // Find out if the weapon_list_widget is empty, and if not empty it
    ui->weapon_list_widget->clear();

    // Find out if motionValueListWidget is empty, and if not empty it
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

void damagecalculatorwindow::on_weapon_type_list_widget_activated(const QModelIndex &index)
{
    damagecalculatorwindow::on_weapon_type_list_widget_clicked(index);
}

void damagecalculatorwindow::on_weapon_list_widget_clicked(const QModelIndex &index)
{
    QString sql;
    QSqlQuery query;

    this->weaponName = index.data(Qt::DisplayRole).toString();

    // Reset this' appropriate weapon type
    this->weaponType = ui->weapon_type_list_widget->currentItem()->data(Qt::DisplayRole).toString();

    // When a weapon is selected here, set the customs to none
    ui->customWeaponsListWidget->setCurrentRow(this->customWeapons.size());

    // If it's not already updated, update the motion values
    ui->motionValueListWidget->clear();
    sql = "SELECT name FROM MotionValues WHERE \"weapon type\"=\"";
    sql.append(this->weaponType);
    sql.append("\"");
    query = runQuery(sql);
    while(query.next())
        ui->motionValueListWidget->addItem(query.value(0).toString());

    // Set the defaults for the motion values (prevent errors)
    ui->motionValueListWidget->setCurrentRow(0);
    on_motionValueListWidget_clicked(ui->motionValueListWidget->currentIndex());
}

void damagecalculatorwindow::on_weapon_list_widget_activated(const QModelIndex &index)
{
    damagecalculatorwindow::on_weapon_list_widget_clicked(index);
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

void damagecalculatorwindow::updateChosenWeapon()
{
    unsigned int row = ui->customWeaponsListWidget->currentRow();
    QSqlQuery query;

    if (row != this->customWeapons.size())
    {
        // Custom weapon selected
        this->chosenWeapon = this->customWeapons[row];
    }
    else
    {
        // Regular weapon selected
        // Name
        this->chosenWeapon.name = this->weaponName;

        // Weapon Type
        this->chosenWeapon.weapon_type = this->weaponType;

        // Attack
        query = findQuery("attack", this->weaponType, "name", this->chosenWeapon.name);
        this->chosenWeapon.attack = query.value(0).toString().toInt();

        // Special
        query = findQuery("special", this->weaponType, "name", this->weaponName);
        this->chosenWeapon.special = query.value(0).toString();
        if (this->chosenWeapon.special == "Fire" || this->chosenWeapon.special == "Ice" ||
                this->chosenWeapon.special == "Water" || this->chosenWeapon.special == "Dragon" ||
                this->chosenWeapon.special == "Thunder")
        {
            query = findQuery("special attack", this->weaponType, "name", this->weaponName);
            this->chosenWeapon.special_attack = query.value(0).toString().toInt();
        }
        else
        {
            this->chosenWeapon.special_attack = 0;
        }

        // Affinity
        query = findQuery("affinity", this->weaponType, "name", this->weaponName);
        this->chosenWeapon.affinity = query.value(0).toString().toInt();

        // Sharpness
        query = findQuery("sharpness", this->weaponType, "name", this->weaponName);
        this->chosenWeapon.sharpness = query.value(0).toString();
        query = findQuery("sharpness+1", this->weaponType, "name", this->weaponName);
        this->chosenWeapon.sharpness1 = query.value(0).toString();

        std::cout << this->chosenWeapon.sharpness.toStdString() << std::endl;
        std::cout << this->chosenWeapon.sharpness1.toStdString() << std::endl;

        // Other maybe one day query for each item
        this->chosenWeapon.rarity = 10;
        this->chosenWeapon.defense = 0;
        this->chosenWeapon.num_slots = 0;
    }
}

void damagecalculatorwindow::on_caclulatePushButton_clicked()
{
    std::map<std::string, std::map<std::string, float> > allModifiers;
    std::map<std::string, float> rawModifiers;
    std::map<std::string, float> eleModifiers;
    std::map<std::string, float> affinityModifiers;
    QString sharpness;
    QString temp;
    float raw = 0;
    float ele = 0;
    float total = 0;
    float rawHitzone;
    float eleHitzone;
    bool artillery;

    // The following gets messy...
    // Update the chosen weapon
    damagecalculatorwindow::updateChosenWeapon();

    // Need to get sharpness
    if (ui->sharpnessCheckBox->isChecked())
        sharpness = this->chosenWeapon.sharpness1;
    else
        sharpness = this->chosenWeapon.sharpness;

    // Need to get all raw modifiers
    rawModifiers["attack"] = float(this->chosenWeapon.attack);

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
        if (this->chosenWeapon.weapon_type == "ChargeBlades")
        {
            if (this->motionValue.contains("Discharge") || (this->motionValue.contains("AED") &&
                                                            !this->motionValue.contains("Phials Empty")))
                artillery = true;
        }
        else if (this->chosenWeapon.weapon_type == "Gunlances")
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
    eleModifiers["specialAttack"] = float(this->chosenWeapon.special_attack);

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
    affinityModifiers["affinity"] = float(this->chosenWeapon.affinity);

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
                                    sharpness.toStdString(), this->chosenWeapon.weapon_type.toStdString(),
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

void damagecalculatorwindow::on_motionValueListWidget_activated(const QModelIndex &index)
{
    damagecalculatorwindow::on_motionValueListWidget_clicked(index);
}

void damagecalculatorwindow::on_addWeaponPushButton_clicked()
{
    addWeaponDialog = new addweapondialog(this);
    addWeaponDialog->exec();
    damagecalculatorwindow::updateCustomWeaponsListWidget();
}

void damagecalculatorwindow::on_customWeaponsListWidget_clicked(const QModelIndex &index)
{
    QString sql;
    QSqlQuery query;

    if (index.data().toString() != "None")
    {
        this->weaponType = this->customWeapons[index.row()].weapon_type;
        ui->motionValueListWidget->clear();
        sql = "SELECT name FROM MotionValues WHERE \"weapon type\"=\"";
        sql.append(this->weaponType);
        sql.append("\"");
        query = runQuery(sql);
        while(query.next())
            ui->motionValueListWidget->addItem(query.value(0).toString());
        ui->motionValueListWidget->setCurrentRow(0);
        damagecalculatorwindow::on_motionValueListWidget_clicked(ui->motionValueListWidget->currentIndex());
    }
}
