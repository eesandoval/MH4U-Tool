/********************************************************************************
** Form generated from reading UI file 'damagecalculatorwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DAMAGECALCULATORWINDOW_H
#define UI_DAMAGECALCULATORWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_damagecalculatorwindow
{
public:
    QWidget *centralwidget;
    QGroupBox *fortifyBox;
    QRadioButton *faint1RadioButton;
    QRadioButton *faint2RadioButton;
    QRadioButton *fortifyNoneRadioButton;
    QGroupBox *dangerBox;
    QRadioButton *heroicsRadioButton;
    QRadioButton *dangerNoneRadioButton;
    QRadioButton *adrenaline2RadioButton;
    QGroupBox *seedPillBox;
    QRadioButton *mightSeedRadioButton;
    QRadioButton *mightPillRadioButton;
    QRadioButton *mightNoneRadioButton;
    QGroupBox *AuXBox;
    QRadioButton *AuSRadioButton;
    QRadioButton *AuMRadioButton;
    QRadioButton *AuLRadioButton;
    QRadioButton *AuXLRadioButton;
    QRadioButton *AuXNoneRadioButton;
    QGroupBox *otherBox;
    QCheckBox *sharpnessCheckBox;
    QCheckBox *powerCharmCheckBox;
    QCheckBox *criticalDrawCheckBox;
    QCheckBox *powerTalonCheckBox;
    QCheckBox *criticalElementCheckBox;
    QCheckBox *wyvernStoneRawCheckBox;
    QCheckBox *wyvernStoneEleCheckBox;
    QCheckBox *checkBox;
    QGroupBox *kitchenBox;
    QRadioButton *AuSKitchenRadioButton;
    QRadioButton *AuLKitchenRadioButton;
    QRadioButton *kitchenNoneRadioButton;
    QGroupBox *gloveBox;
    QRadioButton *latentPower1RadioButton;
    QRadioButton *latentPower2RadioButton;
    QRadioButton *challenger1RadioButton;
    QRadioButton *challenger2RadioButton;
    QRadioButton *gloveNoneRadioButton;
    QRadioButton *peakPerformanceRadioButton;
    QGroupBox *huntingHornBox;
    QRadioButton *attackUpSRadioButton;
    QRadioButton *attackUpLRadioButton;
    QCheckBox *replayCheckBox;
    QRadioButton *HHNoneRadioButton;
    QCheckBox *affinityUpCheckBox;
    QCheckBox *elementUpCheckBox;
    QGroupBox *criticalEyeBox;
    QRadioButton *criticalEye1RadioButton;
    QRadioButton *criticalEye2RadioButton;
    QRadioButton *criticalEye3RadioButton;
    QRadioButton *criticalGodRadioButton;
    QRadioButton *CENoneRadioButton;
    QGroupBox *elementBox;
    QRadioButton *element1RadioButton;
    QRadioButton *element2RadioButton;
    QRadioButton *element3RadioButton;
    QCheckBox *elementAtkUpCheckBox;
    QRadioButton *elementNoneRadioButton;
    QTabWidget *damageTabWidget;
    QWidget *displayBasicTab;
    QLabel *totalDamageLabel;
    QLabel *totalDamageFloatLabel;
    QLabel *rawDamageLabel;
    QLabel *rawDamageFloatLabel;
    QLabel *elementalDamageLabel;
    QLabel *eleDamageFloatLabel;
    QPushButton *caclulatePushButton;
    QWidget *displayAdvancedTab;
    QLabel *motionValueNameLabel;
    QLabel *numberOfAttacksLabel;
    QLabel *numAttacksLabel;
    QLabel *label;
    QLabel *averageRawDamagePerLabel;
    QLabel *label_3;
    QLabel *averageEleDamagePerLabel;
    QLabel *label_5;
    QLabel *averageTotalNumberPerLabel;
    QGroupBox *artilleryGroupBox;
    QRadioButton *artilleryNoviceRadioButton;
    QRadioButton *artilleryExpertRadioButton;
    QRadioButton *artilleryGodRadioButton;
    QRadioButton *artilleryNoneRadioButton;
    QGroupBox *weaponSpecificGroupBox;
    QRadioButton *tripleUpRadioButton;
    QRadioButton *boostModeRadioButton;
    QRadioButton *weaponSpecificNoneRadioButton;
    QRadioButton *critDistanceRadioButton;
    QRadioButton *CoBRadioButton;
    QRadioButton *demonModeRadioButton;
    QCheckBox *rawHoneCheckBox;
    QGroupBox *customWeaponGroupBox;
    QLabel *customAttackLabel;
    QLabel *customElementLabel;
    QComboBox *customWeaponTypeComboBox;
    QLabel *customWeaponTypeLabel;
    QPushButton *addWeaponPushButton;
    QSpinBox *spinBox;
    QSpinBox *spinBox_3;
    QLabel *customAffinityLabel;
    QDoubleSpinBox *doubleSpinBox;
    QComboBox *comboBox;
    QLabel *label_2;
    QGroupBox *hitzonesGroupBox;
    QLabel *rawHitzoneTextLabel;
    QLabel *eleHitzoneTextLabel;
    QCheckBox *weaknessExploitCheckBox;
    QSpinBox *rawHitzoneSpinBox;
    QSpinBox *eleHitzoneSpinBox;
    QGroupBox *weaponTypeGroupBox;
    QListWidget *weapon_type_list_widget;
    QGroupBox *weaponGroupBox;
    QListWidget *weapon_list_widget;
    QGroupBox *motionValueGroupBox;
    QListWidget *motionValueListWidget;
    QLabel *motionValueStringLabel;
    QMenuBar *menubar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *damagecalculatorwindow)
    {
        if (damagecalculatorwindow->objectName().isEmpty())
            damagecalculatorwindow->setObjectName(QStringLiteral("damagecalculatorwindow"));
        damagecalculatorwindow->resize(833, 568);
        centralwidget = new QWidget(damagecalculatorwindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        fortifyBox = new QGroupBox(centralwidget);
        fortifyBox->setObjectName(QStringLiteral("fortifyBox"));
        fortifyBox->setGeometry(QRect(220, 160, 71, 80));
        faint1RadioButton = new QRadioButton(fortifyBox);
        faint1RadioButton->setObjectName(QStringLiteral("faint1RadioButton"));
        faint1RadioButton->setGeometry(QRect(0, 20, 71, 22));
        faint2RadioButton = new QRadioButton(fortifyBox);
        faint2RadioButton->setObjectName(QStringLiteral("faint2RadioButton"));
        faint2RadioButton->setGeometry(QRect(0, 40, 71, 22));
        fortifyNoneRadioButton = new QRadioButton(fortifyBox);
        fortifyNoneRadioButton->setObjectName(QStringLiteral("fortifyNoneRadioButton"));
        fortifyNoneRadioButton->setGeometry(QRect(0, 60, 71, 22));
        dangerBox = new QGroupBox(centralwidget);
        dangerBox->setObjectName(QStringLiteral("dangerBox"));
        dangerBox->setGeometry(QRect(310, 270, 101, 81));
        heroicsRadioButton = new QRadioButton(dangerBox);
        heroicsRadioButton->setObjectName(QStringLiteral("heroicsRadioButton"));
        heroicsRadioButton->setGeometry(QRect(0, 20, 81, 22));
        dangerNoneRadioButton = new QRadioButton(dangerBox);
        dangerNoneRadioButton->setObjectName(QStringLiteral("dangerNoneRadioButton"));
        dangerNoneRadioButton->setGeometry(QRect(0, 60, 71, 22));
        adrenaline2RadioButton = new QRadioButton(dangerBox);
        adrenaline2RadioButton->setObjectName(QStringLiteral("adrenaline2RadioButton"));
        adrenaline2RadioButton->setGeometry(QRect(0, 40, 101, 22));
        seedPillBox = new QGroupBox(centralwidget);
        seedPillBox->setObjectName(QStringLiteral("seedPillBox"));
        seedPillBox->setGeometry(QRect(220, 270, 81, 81));
        mightSeedRadioButton = new QRadioButton(seedPillBox);
        mightSeedRadioButton->setObjectName(QStringLiteral("mightSeedRadioButton"));
        mightSeedRadioButton->setGeometry(QRect(0, 20, 61, 22));
        mightPillRadioButton = new QRadioButton(seedPillBox);
        mightPillRadioButton->setObjectName(QStringLiteral("mightPillRadioButton"));
        mightPillRadioButton->setGeometry(QRect(0, 40, 51, 22));
        mightNoneRadioButton = new QRadioButton(seedPillBox);
        mightNoneRadioButton->setObjectName(QStringLiteral("mightNoneRadioButton"));
        mightNoneRadioButton->setGeometry(QRect(0, 60, 71, 22));
        AuXBox = new QGroupBox(centralwidget);
        AuXBox->setObjectName(QStringLiteral("AuXBox"));
        AuXBox->setGeometry(QRect(310, 0, 71, 121));
        AuSRadioButton = new QRadioButton(AuXBox);
        AuSRadioButton->setObjectName(QStringLiteral("AuSRadioButton"));
        AuSRadioButton->setGeometry(QRect(0, 20, 61, 22));
        AuMRadioButton = new QRadioButton(AuXBox);
        AuMRadioButton->setObjectName(QStringLiteral("AuMRadioButton"));
        AuMRadioButton->setGeometry(QRect(0, 40, 61, 22));
        AuLRadioButton = new QRadioButton(AuXBox);
        AuLRadioButton->setObjectName(QStringLiteral("AuLRadioButton"));
        AuLRadioButton->setGeometry(QRect(0, 60, 61, 22));
        AuXLRadioButton = new QRadioButton(AuXBox);
        AuXLRadioButton->setObjectName(QStringLiteral("AuXLRadioButton"));
        AuXLRadioButton->setGeometry(QRect(0, 80, 71, 22));
        AuXNoneRadioButton = new QRadioButton(AuXBox);
        AuXNoneRadioButton->setObjectName(QStringLiteral("AuXNoneRadioButton"));
        AuXNoneRadioButton->setGeometry(QRect(0, 100, 71, 22));
        otherBox = new QGroupBox(centralwidget);
        otherBox->setObjectName(QStringLiteral("otherBox"));
        otherBox->setGeometry(QRect(680, 160, 151, 181));
        sharpnessCheckBox = new QCheckBox(otherBox);
        sharpnessCheckBox->setObjectName(QStringLiteral("sharpnessCheckBox"));
        sharpnessCheckBox->setGeometry(QRect(0, 20, 111, 22));
        powerCharmCheckBox = new QCheckBox(otherBox);
        powerCharmCheckBox->setObjectName(QStringLiteral("powerCharmCheckBox"));
        powerCharmCheckBox->setGeometry(QRect(0, 100, 121, 22));
        criticalDrawCheckBox = new QCheckBox(otherBox);
        criticalDrawCheckBox->setObjectName(QStringLiteral("criticalDrawCheckBox"));
        criticalDrawCheckBox->setGeometry(QRect(0, 80, 121, 22));
        powerTalonCheckBox = new QCheckBox(otherBox);
        powerTalonCheckBox->setObjectName(QStringLiteral("powerTalonCheckBox"));
        powerTalonCheckBox->setGeometry(QRect(0, 120, 111, 22));
        criticalElementCheckBox = new QCheckBox(otherBox);
        criticalElementCheckBox->setObjectName(QStringLiteral("criticalElementCheckBox"));
        criticalElementCheckBox->setGeometry(QRect(0, 60, 141, 22));
        wyvernStoneRawCheckBox = new QCheckBox(otherBox);
        wyvernStoneRawCheckBox->setObjectName(QStringLiteral("wyvernStoneRawCheckBox"));
        wyvernStoneRawCheckBox->setGeometry(QRect(0, 140, 121, 22));
        wyvernStoneEleCheckBox = new QCheckBox(otherBox);
        wyvernStoneEleCheckBox->setObjectName(QStringLiteral("wyvernStoneEleCheckBox"));
        wyvernStoneEleCheckBox->setGeometry(QRect(0, 160, 121, 22));
        checkBox = new QCheckBox(otherBox);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(0, 40, 97, 22));
        kitchenBox = new QGroupBox(centralwidget);
        kitchenBox->setObjectName(QStringLiteral("kitchenBox"));
        kitchenBox->setGeometry(QRect(310, 160, 81, 80));
        AuSKitchenRadioButton = new QRadioButton(kitchenBox);
        AuSKitchenRadioButton->setObjectName(QStringLiteral("AuSKitchenRadioButton"));
        AuSKitchenRadioButton->setGeometry(QRect(0, 20, 61, 22));
        AuLKitchenRadioButton = new QRadioButton(kitchenBox);
        AuLKitchenRadioButton->setObjectName(QStringLiteral("AuLKitchenRadioButton"));
        AuLKitchenRadioButton->setGeometry(QRect(0, 40, 61, 22));
        kitchenNoneRadioButton = new QRadioButton(kitchenBox);
        kitchenNoneRadioButton->setObjectName(QStringLiteral("kitchenNoneRadioButton"));
        kitchenNoneRadioButton->setGeometry(QRect(0, 60, 71, 22));
        gloveBox = new QGroupBox(centralwidget);
        gloveBox->setObjectName(QStringLiteral("gloveBox"));
        gloveBox->setGeometry(QRect(140, 0, 151, 141));
        latentPower1RadioButton = new QRadioButton(gloveBox);
        latentPower1RadioButton->setObjectName(QStringLiteral("latentPower1RadioButton"));
        latentPower1RadioButton->setGeometry(QRect(0, 20, 141, 22));
        latentPower2RadioButton = new QRadioButton(gloveBox);
        latentPower2RadioButton->setObjectName(QStringLiteral("latentPower2RadioButton"));
        latentPower2RadioButton->setGeometry(QRect(0, 40, 141, 22));
        challenger1RadioButton = new QRadioButton(gloveBox);
        challenger1RadioButton->setObjectName(QStringLiteral("challenger1RadioButton"));
        challenger1RadioButton->setGeometry(QRect(0, 60, 121, 22));
        challenger2RadioButton = new QRadioButton(gloveBox);
        challenger2RadioButton->setObjectName(QStringLiteral("challenger2RadioButton"));
        challenger2RadioButton->setGeometry(QRect(0, 80, 121, 22));
        gloveNoneRadioButton = new QRadioButton(gloveBox);
        gloveNoneRadioButton->setObjectName(QStringLiteral("gloveNoneRadioButton"));
        gloveNoneRadioButton->setGeometry(QRect(0, 120, 71, 22));
        peakPerformanceRadioButton = new QRadioButton(gloveBox);
        peakPerformanceRadioButton->setObjectName(QStringLiteral("peakPerformanceRadioButton"));
        peakPerformanceRadioButton->setGeometry(QRect(0, 100, 151, 22));
        huntingHornBox = new QGroupBox(centralwidget);
        huntingHornBox->setObjectName(QStringLiteral("huntingHornBox"));
        huntingHornBox->setGeometry(QRect(680, 0, 120, 141));
        attackUpSRadioButton = new QRadioButton(huntingHornBox);
        attackUpSRadioButton->setObjectName(QStringLiteral("attackUpSRadioButton"));
        attackUpSRadioButton->setGeometry(QRect(0, 20, 117, 22));
        attackUpLRadioButton = new QRadioButton(huntingHornBox);
        attackUpLRadioButton->setObjectName(QStringLiteral("attackUpLRadioButton"));
        attackUpLRadioButton->setGeometry(QRect(0, 40, 117, 22));
        replayCheckBox = new QCheckBox(huntingHornBox);
        replayCheckBox->setObjectName(QStringLiteral("replayCheckBox"));
        replayCheckBox->setGeometry(QRect(0, 100, 81, 22));
        HHNoneRadioButton = new QRadioButton(huntingHornBox);
        HHNoneRadioButton->setObjectName(QStringLiteral("HHNoneRadioButton"));
        HHNoneRadioButton->setGeometry(QRect(0, 120, 71, 22));
        affinityUpCheckBox = new QCheckBox(huntingHornBox);
        affinityUpCheckBox->setObjectName(QStringLiteral("affinityUpCheckBox"));
        affinityUpCheckBox->setGeometry(QRect(0, 60, 111, 22));
        elementUpCheckBox = new QCheckBox(huntingHornBox);
        elementUpCheckBox->setObjectName(QStringLiteral("elementUpCheckBox"));
        elementUpCheckBox->setGeometry(QRect(0, 80, 111, 22));
        criticalEyeBox = new QGroupBox(centralwidget);
        criticalEyeBox->setObjectName(QStringLiteral("criticalEyeBox"));
        criticalEyeBox->setGeometry(QRect(410, 0, 120, 121));
        criticalEye1RadioButton = new QRadioButton(criticalEyeBox);
        criticalEye1RadioButton->setObjectName(QStringLiteral("criticalEye1RadioButton"));
        criticalEye1RadioButton->setGeometry(QRect(0, 20, 117, 22));
        criticalEye2RadioButton = new QRadioButton(criticalEyeBox);
        criticalEye2RadioButton->setObjectName(QStringLiteral("criticalEye2RadioButton"));
        criticalEye2RadioButton->setGeometry(QRect(0, 40, 117, 22));
        criticalEye3RadioButton = new QRadioButton(criticalEyeBox);
        criticalEye3RadioButton->setObjectName(QStringLiteral("criticalEye3RadioButton"));
        criticalEye3RadioButton->setGeometry(QRect(0, 60, 117, 22));
        criticalGodRadioButton = new QRadioButton(criticalEyeBox);
        criticalGodRadioButton->setObjectName(QStringLiteral("criticalGodRadioButton"));
        criticalGodRadioButton->setGeometry(QRect(0, 80, 111, 22));
        CENoneRadioButton = new QRadioButton(criticalEyeBox);
        CENoneRadioButton->setObjectName(QStringLiteral("CENoneRadioButton"));
        CENoneRadioButton->setGeometry(QRect(0, 100, 71, 22));
        elementBox = new QGroupBox(centralwidget);
        elementBox->setObjectName(QStringLiteral("elementBox"));
        elementBox->setGeometry(QRect(540, 0, 131, 121));
        element1RadioButton = new QRadioButton(elementBox);
        element1RadioButton->setObjectName(QStringLiteral("element1RadioButton"));
        element1RadioButton->setGeometry(QRect(0, 20, 101, 22));
        element2RadioButton = new QRadioButton(elementBox);
        element2RadioButton->setObjectName(QStringLiteral("element2RadioButton"));
        element2RadioButton->setGeometry(QRect(0, 40, 101, 22));
        element3RadioButton = new QRadioButton(elementBox);
        element3RadioButton->setObjectName(QStringLiteral("element3RadioButton"));
        element3RadioButton->setGeometry(QRect(0, 60, 101, 22));
        elementAtkUpCheckBox = new QCheckBox(elementBox);
        elementAtkUpCheckBox->setObjectName(QStringLiteral("elementAtkUpCheckBox"));
        elementAtkUpCheckBox->setGeometry(QRect(0, 80, 131, 22));
        elementNoneRadioButton = new QRadioButton(elementBox);
        elementNoneRadioButton->setObjectName(QStringLiteral("elementNoneRadioButton"));
        elementNoneRadioButton->setGeometry(QRect(0, 100, 71, 22));
        damageTabWidget = new QTabWidget(centralwidget);
        damageTabWidget->setObjectName(QStringLiteral("damageTabWidget"));
        damageTabWidget->setGeometry(QRect(280, 360, 241, 161));
        displayBasicTab = new QWidget();
        displayBasicTab->setObjectName(QStringLiteral("displayBasicTab"));
        totalDamageLabel = new QLabel(displayBasicTab);
        totalDamageLabel->setObjectName(QStringLiteral("totalDamageLabel"));
        totalDamageLabel->setGeometry(QRect(0, 0, 94, 17));
        totalDamageFloatLabel = new QLabel(displayBasicTab);
        totalDamageFloatLabel->setObjectName(QStringLiteral("totalDamageFloatLabel"));
        totalDamageFloatLabel->setGeometry(QRect(160, 0, 51, 20));
        rawDamageLabel = new QLabel(displayBasicTab);
        rawDamageLabel->setObjectName(QStringLiteral("rawDamageLabel"));
        rawDamageLabel->setGeometry(QRect(0, 40, 89, 17));
        rawDamageFloatLabel = new QLabel(displayBasicTab);
        rawDamageFloatLabel->setObjectName(QStringLiteral("rawDamageFloatLabel"));
        rawDamageFloatLabel->setGeometry(QRect(160, 40, 51, 20));
        elementalDamageLabel = new QLabel(displayBasicTab);
        elementalDamageLabel->setObjectName(QStringLiteral("elementalDamageLabel"));
        elementalDamageLabel->setGeometry(QRect(0, 80, 81, 17));
        eleDamageFloatLabel = new QLabel(displayBasicTab);
        eleDamageFloatLabel->setObjectName(QStringLiteral("eleDamageFloatLabel"));
        eleDamageFloatLabel->setGeometry(QRect(160, 80, 51, 20));
        caclulatePushButton = new QPushButton(displayBasicTab);
        caclulatePushButton->setObjectName(QStringLiteral("caclulatePushButton"));
        caclulatePushButton->setGeometry(QRect(70, 100, 85, 27));
        damageTabWidget->addTab(displayBasicTab, QString());
        displayAdvancedTab = new QWidget();
        displayAdvancedTab->setObjectName(QStringLiteral("displayAdvancedTab"));
        motionValueNameLabel = new QLabel(displayAdvancedTab);
        motionValueNameLabel->setObjectName(QStringLiteral("motionValueNameLabel"));
        motionValueNameLabel->setGeometry(QRect(0, 0, 221, 17));
        numberOfAttacksLabel = new QLabel(displayAdvancedTab);
        numberOfAttacksLabel->setObjectName(QStringLiteral("numberOfAttacksLabel"));
        numberOfAttacksLabel->setGeometry(QRect(0, 30, 141, 17));
        numAttacksLabel = new QLabel(displayAdvancedTab);
        numAttacksLabel->setObjectName(QStringLiteral("numAttacksLabel"));
        numAttacksLabel->setGeometry(QRect(190, 30, 41, 17));
        label = new QLabel(displayAdvancedTab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 50, 211, 17));
        averageRawDamagePerLabel = new QLabel(displayAdvancedTab);
        averageRawDamagePerLabel->setObjectName(QStringLiteral("averageRawDamagePerLabel"));
        averageRawDamagePerLabel->setGeometry(QRect(190, 50, 41, 17));
        label_3 = new QLabel(displayAdvancedTab);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(0, 70, 181, 17));
        averageEleDamagePerLabel = new QLabel(displayAdvancedTab);
        averageEleDamagePerLabel->setObjectName(QStringLiteral("averageEleDamagePerLabel"));
        averageEleDamagePerLabel->setGeometry(QRect(190, 70, 41, 17));
        label_5 = new QLabel(displayAdvancedTab);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(0, 100, 191, 17));
        averageTotalNumberPerLabel = new QLabel(displayAdvancedTab);
        averageTotalNumberPerLabel->setObjectName(QStringLiteral("averageTotalNumberPerLabel"));
        averageTotalNumberPerLabel->setGeometry(QRect(190, 100, 41, 17));
        damageTabWidget->addTab(displayAdvancedTab, QString());
        artilleryGroupBox = new QGroupBox(centralwidget);
        artilleryGroupBox->setObjectName(QStringLiteral("artilleryGroupBox"));
        artilleryGroupBox->setGeometry(QRect(540, 160, 131, 101));
        artilleryNoviceRadioButton = new QRadioButton(artilleryGroupBox);
        artilleryNoviceRadioButton->setObjectName(QStringLiteral("artilleryNoviceRadioButton"));
        artilleryNoviceRadioButton->setGeometry(QRect(0, 20, 141, 22));
        artilleryExpertRadioButton = new QRadioButton(artilleryGroupBox);
        artilleryExpertRadioButton->setObjectName(QStringLiteral("artilleryExpertRadioButton"));
        artilleryExpertRadioButton->setGeometry(QRect(0, 40, 141, 22));
        artilleryGodRadioButton = new QRadioButton(artilleryGroupBox);
        artilleryGodRadioButton->setObjectName(QStringLiteral("artilleryGodRadioButton"));
        artilleryGodRadioButton->setGeometry(QRect(0, 60, 121, 22));
        artilleryNoneRadioButton = new QRadioButton(artilleryGroupBox);
        artilleryNoneRadioButton->setObjectName(QStringLiteral("artilleryNoneRadioButton"));
        artilleryNoneRadioButton->setGeometry(QRect(0, 80, 71, 22));
        weaponSpecificGroupBox = new QGroupBox(centralwidget);
        weaponSpecificGroupBox->setObjectName(QStringLiteral("weaponSpecificGroupBox"));
        weaponSpecificGroupBox->setGeometry(QRect(410, 160, 121, 161));
        tripleUpRadioButton = new QRadioButton(weaponSpecificGroupBox);
        tripleUpRadioButton->setObjectName(QStringLiteral("tripleUpRadioButton"));
        tripleUpRadioButton->setGeometry(QRect(0, 40, 91, 22));
        boostModeRadioButton = new QRadioButton(weaponSpecificGroupBox);
        boostModeRadioButton->setObjectName(QStringLiteral("boostModeRadioButton"));
        boostModeRadioButton->setGeometry(QRect(0, 60, 117, 22));
        weaponSpecificNoneRadioButton = new QRadioButton(weaponSpecificGroupBox);
        weaponSpecificNoneRadioButton->setObjectName(QStringLiteral("weaponSpecificNoneRadioButton"));
        weaponSpecificNoneRadioButton->setGeometry(QRect(0, 140, 71, 22));
        critDistanceRadioButton = new QRadioButton(weaponSpecificGroupBox);
        critDistanceRadioButton->setObjectName(QStringLiteral("critDistanceRadioButton"));
        critDistanceRadioButton->setGeometry(QRect(0, 80, 121, 22));
        CoBRadioButton = new QRadioButton(weaponSpecificGroupBox);
        CoBRadioButton->setObjectName(QStringLiteral("CoBRadioButton"));
        CoBRadioButton->setGeometry(QRect(0, 20, 61, 22));
        demonModeRadioButton = new QRadioButton(weaponSpecificGroupBox);
        demonModeRadioButton->setObjectName(QStringLiteral("demonModeRadioButton"));
        demonModeRadioButton->setGeometry(QRect(0, 100, 117, 22));
        rawHoneCheckBox = new QCheckBox(weaponSpecificGroupBox);
        rawHoneCheckBox->setObjectName(QStringLiteral("rawHoneCheckBox"));
        rawHoneCheckBox->setGeometry(QRect(0, 120, 101, 22));
        customWeaponGroupBox = new QGroupBox(centralwidget);
        customWeaponGroupBox->setObjectName(QStringLiteral("customWeaponGroupBox"));
        customWeaponGroupBox->setGeometry(QRect(530, 400, 291, 121));
        customAttackLabel = new QLabel(customWeaponGroupBox);
        customAttackLabel->setObjectName(QStringLiteral("customAttackLabel"));
        customAttackLabel->setGeometry(QRect(0, 70, 67, 17));
        customElementLabel = new QLabel(customWeaponGroupBox);
        customElementLabel->setObjectName(QStringLiteral("customElementLabel"));
        customElementLabel->setGeometry(QRect(70, 70, 101, 17));
        customWeaponTypeComboBox = new QComboBox(customWeaponGroupBox);
        customWeaponTypeComboBox->setObjectName(QStringLiteral("customWeaponTypeComboBox"));
        customWeaponTypeComboBox->setGeometry(QRect(0, 40, 151, 27));
        customWeaponTypeLabel = new QLabel(customWeaponGroupBox);
        customWeaponTypeLabel->setObjectName(QStringLiteral("customWeaponTypeLabel"));
        customWeaponTypeLabel->setGeometry(QRect(0, 20, 101, 17));
        addWeaponPushButton = new QPushButton(customWeaponGroupBox);
        addWeaponPushButton->setObjectName(QStringLiteral("addWeaponPushButton"));
        addWeaponPushButton->setGeometry(QRect(210, 90, 71, 27));
        spinBox = new QSpinBox(customWeaponGroupBox);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(0, 90, 61, 27));
        spinBox_3 = new QSpinBox(customWeaponGroupBox);
        spinBox_3->setObjectName(QStringLiteral("spinBox_3"));
        spinBox_3->setGeometry(QRect(70, 90, 61, 27));
        customAffinityLabel = new QLabel(customWeaponGroupBox);
        customAffinityLabel->setObjectName(QStringLiteral("customAffinityLabel"));
        customAffinityLabel->setGeometry(QRect(140, 70, 67, 17));
        doubleSpinBox = new QDoubleSpinBox(customWeaponGroupBox);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        doubleSpinBox->setGeometry(QRect(140, 90, 69, 27));
        comboBox = new QComboBox(customWeaponGroupBox);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(190, 40, 101, 27));
        label_2 = new QLabel(customWeaponGroupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(190, 20, 131, 17));
        hitzonesGroupBox = new QGroupBox(centralwidget);
        hitzonesGroupBox->setObjectName(QStringLiteral("hitzonesGroupBox"));
        hitzonesGroupBox->setGeometry(QRect(540, 270, 131, 101));
        rawHitzoneTextLabel = new QLabel(hitzonesGroupBox);
        rawHitzoneTextLabel->setObjectName(QStringLiteral("rawHitzoneTextLabel"));
        rawHitzoneTextLabel->setGeometry(QRect(0, 20, 67, 17));
        eleHitzoneTextLabel = new QLabel(hitzonesGroupBox);
        eleHitzoneTextLabel->setObjectName(QStringLiteral("eleHitzoneTextLabel"));
        eleHitzoneTextLabel->setGeometry(QRect(0, 50, 67, 17));
        weaknessExploitCheckBox = new QCheckBox(hitzonesGroupBox);
        weaknessExploitCheckBox->setObjectName(QStringLiteral("weaknessExploitCheckBox"));
        weaknessExploitCheckBox->setGeometry(QRect(0, 80, 101, 22));
        rawHitzoneSpinBox = new QSpinBox(hitzonesGroupBox);
        rawHitzoneSpinBox->setObjectName(QStringLiteral("rawHitzoneSpinBox"));
        rawHitzoneSpinBox->setGeometry(QRect(57, 20, 71, 27));
        eleHitzoneSpinBox = new QSpinBox(hitzonesGroupBox);
        eleHitzoneSpinBox->setObjectName(QStringLiteral("eleHitzoneSpinBox"));
        eleHitzoneSpinBox->setGeometry(QRect(57, 50, 71, 27));
        weaponTypeGroupBox = new QGroupBox(centralwidget);
        weaponTypeGroupBox->setObjectName(QStringLiteral("weaponTypeGroupBox"));
        weaponTypeGroupBox->setGeometry(QRect(10, 0, 121, 161));
        weapon_type_list_widget = new QListWidget(weaponTypeGroupBox);
        new QListWidgetItem(weapon_type_list_widget);
        new QListWidgetItem(weapon_type_list_widget);
        new QListWidgetItem(weapon_type_list_widget);
        new QListWidgetItem(weapon_type_list_widget);
        weapon_type_list_widget->setObjectName(QStringLiteral("weapon_type_list_widget"));
        weapon_type_list_widget->setGeometry(QRect(0, 20, 121, 141));
        weaponGroupBox = new QGroupBox(centralwidget);
        weaponGroupBox->setObjectName(QStringLiteral("weaponGroupBox"));
        weaponGroupBox->setGeometry(QRect(10, 160, 201, 181));
        weapon_list_widget = new QListWidget(weaponGroupBox);
        weapon_list_widget->setObjectName(QStringLiteral("weapon_list_widget"));
        weapon_list_widget->setGeometry(QRect(0, 20, 201, 161));
        motionValueGroupBox = new QGroupBox(centralwidget);
        motionValueGroupBox->setObjectName(QStringLiteral("motionValueGroupBox"));
        motionValueGroupBox->setGeometry(QRect(10, 350, 261, 171));
        motionValueListWidget = new QListWidget(motionValueGroupBox);
        motionValueListWidget->setObjectName(QStringLiteral("motionValueListWidget"));
        motionValueListWidget->setGeometry(QRect(0, 20, 261, 151));
        motionValueStringLabel = new QLabel(motionValueGroupBox);
        motionValueStringLabel->setObjectName(QStringLiteral("motionValueStringLabel"));
        motionValueStringLabel->setGeometry(QRect(100, 0, 151, 17));
        damagecalculatorwindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(damagecalculatorwindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 833, 25));
        damagecalculatorwindow->setMenuBar(menubar);
        toolBar = new QToolBar(damagecalculatorwindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        damagecalculatorwindow->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(damagecalculatorwindow);

        damageTabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(damagecalculatorwindow);
    } // setupUi

    void retranslateUi(QMainWindow *damagecalculatorwindow)
    {
        damagecalculatorwindow->setWindowTitle(QApplication::translate("damagecalculatorwindow", "Damage Calculator", 0));
        fortifyBox->setTitle(QApplication::translate("damagecalculatorwindow", "Fortify", 0));
        faint1RadioButton->setText(QApplication::translate("damagecalculatorwindow", "Cartx1", 0));
        faint2RadioButton->setText(QApplication::translate("damagecalculatorwindow", "Cartx2", 0));
        fortifyNoneRadioButton->setText(QApplication::translate("damagecalculatorwindow", "None", 0));
        dangerBox->setTitle(QApplication::translate("damagecalculatorwindow", "Danger", 0));
        heroicsRadioButton->setText(QApplication::translate("damagecalculatorwindow", "Heroics", 0));
        dangerNoneRadioButton->setText(QApplication::translate("damagecalculatorwindow", "None", 0));
        adrenaline2RadioButton->setText(QApplication::translate("damagecalculatorwindow", "Adrenaline", 0));
        seedPillBox->setTitle(QApplication::translate("damagecalculatorwindow", "Might Item", 0));
        mightSeedRadioButton->setText(QApplication::translate("damagecalculatorwindow", "Seed", 0));
        mightPillRadioButton->setText(QApplication::translate("damagecalculatorwindow", "Pill", 0));
        mightNoneRadioButton->setText(QApplication::translate("damagecalculatorwindow", "None", 0));
        AuXBox->setTitle(QApplication::translate("damagecalculatorwindow", "AuX", 0));
        AuSRadioButton->setText(QApplication::translate("damagecalculatorwindow", "AuS", 0));
        AuMRadioButton->setText(QApplication::translate("damagecalculatorwindow", "AuM", 0));
        AuLRadioButton->setText(QApplication::translate("damagecalculatorwindow", "AuL", 0));
        AuXLRadioButton->setText(QApplication::translate("damagecalculatorwindow", "AuXL", 0));
        AuXNoneRadioButton->setText(QApplication::translate("damagecalculatorwindow", "None", 0));
        otherBox->setTitle(QApplication::translate("damagecalculatorwindow", "Other", 0));
        sharpnessCheckBox->setText(QApplication::translate("damagecalculatorwindow", "Sharpness+1", 0));
        powerCharmCheckBox->setText(QApplication::translate("damagecalculatorwindow", "Power Charm", 0));
        criticalDrawCheckBox->setText(QApplication::translate("damagecalculatorwindow", "Critical Draw", 0));
        powerTalonCheckBox->setText(QApplication::translate("damagecalculatorwindow", "Power Talon", 0));
        criticalElementCheckBox->setText(QApplication::translate("damagecalculatorwindow", "Critical Element", 0));
        wyvernStoneRawCheckBox->setText(QApplication::translate("damagecalculatorwindow", "Wyvern (Raw)", 0));
        wyvernStoneEleCheckBox->setText(QApplication::translate("damagecalculatorwindow", "Wyvern (Ele)", 0));
        checkBox->setText(QApplication::translate("damagecalculatorwindow", "Ammo Up", 0));
        kitchenBox->setTitle(QApplication::translate("damagecalculatorwindow", "Kitchen", 0));
        AuSKitchenRadioButton->setText(QApplication::translate("damagecalculatorwindow", "AuS", 0));
        AuLKitchenRadioButton->setText(QApplication::translate("damagecalculatorwindow", "AuL", 0));
        kitchenNoneRadioButton->setText(QApplication::translate("damagecalculatorwindow", "None", 0));
        gloveBox->setTitle(QApplication::translate("damagecalculatorwindow", "Glove", 0));
        latentPower1RadioButton->setText(QApplication::translate("damagecalculatorwindow", "Latent Power+1", 0));
        latentPower2RadioButton->setText(QApplication::translate("damagecalculatorwindow", "Latent Power+2", 0));
        challenger1RadioButton->setText(QApplication::translate("damagecalculatorwindow", "Challenger+1", 0));
        challenger2RadioButton->setText(QApplication::translate("damagecalculatorwindow", "Challenger+2", 0));
        gloveNoneRadioButton->setText(QApplication::translate("damagecalculatorwindow", "None", 0));
        peakPerformanceRadioButton->setText(QApplication::translate("damagecalculatorwindow", "Peak Performance", 0));
        huntingHornBox->setTitle(QApplication::translate("damagecalculatorwindow", "Hunting Horn", 0));
        attackUpSRadioButton->setText(QApplication::translate("damagecalculatorwindow", "Attack Up (S)", 0));
        attackUpLRadioButton->setText(QApplication::translate("damagecalculatorwindow", "Attack Up (L)", 0));
        replayCheckBox->setText(QApplication::translate("damagecalculatorwindow", "Replay", 0));
        HHNoneRadioButton->setText(QApplication::translate("damagecalculatorwindow", "None", 0));
        affinityUpCheckBox->setText(QApplication::translate("damagecalculatorwindow", "Affinity Up", 0));
        elementUpCheckBox->setText(QApplication::translate("damagecalculatorwindow", "Element Up", 0));
        criticalEyeBox->setTitle(QApplication::translate("damagecalculatorwindow", "Critical Eye", 0));
        criticalEye1RadioButton->setText(QApplication::translate("damagecalculatorwindow", "Critical Eye+1", 0));
        criticalEye2RadioButton->setText(QApplication::translate("damagecalculatorwindow", "Critical Eye+2", 0));
        criticalEye3RadioButton->setText(QApplication::translate("damagecalculatorwindow", "Critical Eye+3", 0));
        criticalGodRadioButton->setText(QApplication::translate("damagecalculatorwindow", "Critical God", 0));
        CENoneRadioButton->setText(QApplication::translate("damagecalculatorwindow", "None", 0));
        elementBox->setTitle(QApplication::translate("damagecalculatorwindow", "Element", 0));
        element1RadioButton->setText(QApplication::translate("damagecalculatorwindow", "Element+1", 0));
        element2RadioButton->setText(QApplication::translate("damagecalculatorwindow", "Element+2", 0));
        element3RadioButton->setText(QApplication::translate("damagecalculatorwindow", "Element+3", 0));
        elementAtkUpCheckBox->setText(QApplication::translate("damagecalculatorwindow", "ElementAtkUp", 0));
        elementNoneRadioButton->setText(QApplication::translate("damagecalculatorwindow", "None", 0));
        totalDamageLabel->setText(QApplication::translate("damagecalculatorwindow", "Total Damage", 0));
        totalDamageFloatLabel->setText(QApplication::translate("damagecalculatorwindow", "0.00", 0));
        rawDamageLabel->setText(QApplication::translate("damagecalculatorwindow", "Raw Damage", 0));
        rawDamageFloatLabel->setText(QApplication::translate("damagecalculatorwindow", "0.00", 0));
        elementalDamageLabel->setText(QApplication::translate("damagecalculatorwindow", "Ele Damage", 0));
        eleDamageFloatLabel->setText(QApplication::translate("damagecalculatorwindow", "0.00", 0));
        caclulatePushButton->setText(QApplication::translate("damagecalculatorwindow", "Calculate", 0));
        damageTabWidget->setTabText(damageTabWidget->indexOf(displayBasicTab), QApplication::translate("damagecalculatorwindow", "Tab 1", 0));
        motionValueNameLabel->setText(QString());
        numberOfAttacksLabel->setText(QApplication::translate("damagecalculatorwindow", "Number of Attacks:", 0));
        numAttacksLabel->setText(QApplication::translate("damagecalculatorwindow", "0", 0));
        label->setText(QApplication::translate("damagecalculatorwindow", "Average Raw Damage Per:", 0));
        averageRawDamagePerLabel->setText(QApplication::translate("damagecalculatorwindow", "0", 0));
        label_3->setText(QApplication::translate("damagecalculatorwindow", "Average Ele Damage Per:", 0));
        averageEleDamagePerLabel->setText(QApplication::translate("damagecalculatorwindow", "0", 0));
        label_5->setText(QApplication::translate("damagecalculatorwindow", "Average Total Damage Per:", 0));
        averageTotalNumberPerLabel->setText(QApplication::translate("damagecalculatorwindow", "0", 0));
        damageTabWidget->setTabText(damageTabWidget->indexOf(displayAdvancedTab), QApplication::translate("damagecalculatorwindow", "Tab 2", 0));
        artilleryGroupBox->setTitle(QApplication::translate("damagecalculatorwindow", "Artillery", 0));
        artilleryNoviceRadioButton->setText(QApplication::translate("damagecalculatorwindow", "Artillery Novice", 0));
        artilleryExpertRadioButton->setText(QApplication::translate("damagecalculatorwindow", "Artillery Expert", 0));
        artilleryGodRadioButton->setText(QApplication::translate("damagecalculatorwindow", "Artillery God", 0));
        artilleryNoneRadioButton->setText(QApplication::translate("damagecalculatorwindow", "None", 0));
        weaponSpecificGroupBox->setTitle(QApplication::translate("damagecalculatorwindow", "Weapon Specifc", 0));
        tripleUpRadioButton->setText(QApplication::translate("damagecalculatorwindow", "Triple Up", 0));
        boostModeRadioButton->setText(QApplication::translate("damagecalculatorwindow", "Boost Mode", 0));
        weaponSpecificNoneRadioButton->setText(QApplication::translate("damagecalculatorwindow", "None", 0));
        critDistanceRadioButton->setText(QApplication::translate("damagecalculatorwindow", "Crit Distance", 0));
        CoBRadioButton->setText(QApplication::translate("damagecalculatorwindow", "CoB", 0));
        demonModeRadioButton->setText(QApplication::translate("damagecalculatorwindow", "Demon Mode", 0));
        rawHoneCheckBox->setText(QApplication::translate("damagecalculatorwindow", "Raw Hone", 0));
        customWeaponGroupBox->setTitle(QApplication::translate("damagecalculatorwindow", "Input Custom Weapon", 0));
        customAttackLabel->setText(QApplication::translate("damagecalculatorwindow", "Attack", 0));
        customElementLabel->setText(QApplication::translate("damagecalculatorwindow", "Element", 0));
        customWeaponTypeComboBox->clear();
        customWeaponTypeComboBox->insertItems(0, QStringList()
         << QApplication::translate("damagecalculatorwindow", "ChargeBlades", 0)
         << QApplication::translate("damagecalculatorwindow", "GreatSwords", 0)
         << QApplication::translate("damagecalculatorwindow", "InsectGlaives", 0)
        );
        customWeaponTypeLabel->setText(QApplication::translate("damagecalculatorwindow", "Weapon Type", 0));
        addWeaponPushButton->setText(QApplication::translate("damagecalculatorwindow", "Add", 0));
        customAffinityLabel->setText(QApplication::translate("damagecalculatorwindow", "Affinity", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("damagecalculatorwindow", "Purple", 0)
         << QApplication::translate("damagecalculatorwindow", "White", 0)
         << QApplication::translate("damagecalculatorwindow", "Blue", 0)
         << QApplication::translate("damagecalculatorwindow", "Green", 0)
         << QApplication::translate("damagecalculatorwindow", "Yellow", 0)
         << QApplication::translate("damagecalculatorwindow", "Orange", 0)
         << QApplication::translate("damagecalculatorwindow", "Red", 0)
        );
        label_2->setText(QApplication::translate("damagecalculatorwindow", "Sharpness", 0));
        hitzonesGroupBox->setTitle(QApplication::translate("damagecalculatorwindow", "Hitzones", 0));
        rawHitzoneTextLabel->setText(QApplication::translate("damagecalculatorwindow", "Raw", 0));
        eleHitzoneTextLabel->setText(QApplication::translate("damagecalculatorwindow", "Ele", 0));
        weaknessExploitCheckBox->setText(QApplication::translate("damagecalculatorwindow", "Weakness", 0));
        weaponTypeGroupBox->setTitle(QApplication::translate("damagecalculatorwindow", "Weapon Type", 0));

        const bool __sortingEnabled = weapon_type_list_widget->isSortingEnabled();
        weapon_type_list_widget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = weapon_type_list_widget->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("damagecalculatorwindow", "DualBlades", 0));
        QListWidgetItem *___qlistwidgetitem1 = weapon_type_list_widget->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("damagecalculatorwindow", "ChargeBlades", 0));
        QListWidgetItem *___qlistwidgetitem2 = weapon_type_list_widget->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("damagecalculatorwindow", "GreatSwords", 0));
        QListWidgetItem *___qlistwidgetitem3 = weapon_type_list_widget->item(3);
        ___qlistwidgetitem3->setText(QApplication::translate("damagecalculatorwindow", "InsectGlaives", 0));
        weapon_type_list_widget->setSortingEnabled(__sortingEnabled);

        weaponGroupBox->setTitle(QApplication::translate("damagecalculatorwindow", "Weapon", 0));
        motionValueGroupBox->setTitle(QApplication::translate("damagecalculatorwindow", "Motion Value", 0));
        motionValueStringLabel->setText(QApplication::translate("damagecalculatorwindow", "[0]", 0));
        toolBar->setWindowTitle(QApplication::translate("damagecalculatorwindow", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class damagecalculatorwindow: public Ui_damagecalculatorwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DAMAGECALCULATORWINDOW_H
