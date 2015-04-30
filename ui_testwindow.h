/********************************************************************************
** Form generated from reading UI file 'testwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTWINDOW_H
#define UI_TESTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_testwindow
{
public:
    QWidget *centralwidget;
    QGroupBox *kitchenBox;
    QRadioButton *AuSKitchenRadioButton;
    QRadioButton *AuLKitchenRadioButton;
    QRadioButton *kitchenNoneRadioButton;
    QLabel *motionValueStringLabel;
    QTabWidget *damageTabWidget;
    QWidget *displayBasicTab;
    QLabel *totalDamageLabel;
    QLabel *totalDamageFloatLabel;
    QLabel *rawDamageLabel;
    QLabel *rawDamageFloatLabel;
    QLabel *elementalDamageLabel;
    QLabel *eleDamageFloatLabel;
    QWidget *displayAdvancedTab;
    QListWidget *motionValueListWidget;
    QGroupBox *gloveBox;
    QRadioButton *latentPower1RadioButton;
    QRadioButton *latentPower2RadioButton;
    QRadioButton *challenger1RadioButton;
    QRadioButton *challenger2RadioButton;
    QRadioButton *gloveNoneRadioButton;
    QRadioButton *peakPerformanceRadioButton;
    QGroupBox *criticalEyeBox;
    QRadioButton *criticalEye1RadioButton;
    QRadioButton *criticalEye2RadioButton;
    QRadioButton *criticalEye3RadioButton;
    QRadioButton *criticalGodRadioButton;
    QRadioButton *CENoneRadioButton;
    QListWidget *weapon_type_list_widget;
    QGroupBox *dangerBox;
    QRadioButton *adrenaline2RadioButton;
    QRadioButton *heroicsRadioButton;
    QRadioButton *dangerNoneRadioButton;
    QGroupBox *huntingHornBox;
    QRadioButton *attackUpSRadioButton;
    QRadioButton *attackUpLRadioButton;
    QCheckBox *replayCheckBox;
    QRadioButton *HHNoneRadioButton;
    QCheckBox *affinityUpCheckBox;
    QCheckBox *elementUpCheckBox;
    QGroupBox *seedPillBox;
    QRadioButton *mightSeedRadioButton;
    QRadioButton *mightPillRadioButton;
    QRadioButton *mightNoneRadioButton;
    QLabel *weaponLabel;
    QGroupBox *AuXBox;
    QRadioButton *AuSRadioButton;
    QRadioButton *AuMRadioButton;
    QRadioButton *AuLRadioButton;
    QRadioButton *AuXLRadioButton;
    QRadioButton *AuXNoneRadioButton;
    QLabel *weaponTypeLabel;
    QListWidget *weapon_list_widget;
    QGroupBox *elementBox;
    QRadioButton *element1RadioButton;
    QRadioButton *element2RadioButton;
    QRadioButton *element3RadioButton;
    QCheckBox *elementAtkUpCheckBox;
    QRadioButton *elementNoneRadioButton;
    QGroupBox *fortifyBox;
    QRadioButton *faint1RadioButton;
    QRadioButton *faint2RadioButton;
    QRadioButton *fortifyNoneRadioButton;
    QPushButton *caclulatePushButton;
    QGroupBox *otherBox;
    QCheckBox *sharpnessCheckBox;
    QCheckBox *weaknessExploitCheckBox;
    QCheckBox *powerCharmCheckBox;
    QCheckBox *criticalDrawCheckBox;
    QCheckBox *powerTalonCheckBox;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QLabel *motionValueLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *testwindow)
    {
        if (testwindow->objectName().isEmpty())
            testwindow->setObjectName(QStringLiteral("testwindow"));
        testwindow->resize(682, 573);
        centralwidget = new QWidget(testwindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        kitchenBox = new QGroupBox(centralwidget);
        kitchenBox->setObjectName(QStringLiteral("kitchenBox"));
        kitchenBox->setGeometry(QRect(400, 170, 120, 80));
        AuSKitchenRadioButton = new QRadioButton(kitchenBox);
        AuSKitchenRadioButton->setObjectName(QStringLiteral("AuSKitchenRadioButton"));
        AuSKitchenRadioButton->setGeometry(QRect(0, 20, 117, 22));
        AuLKitchenRadioButton = new QRadioButton(kitchenBox);
        AuLKitchenRadioButton->setObjectName(QStringLiteral("AuLKitchenRadioButton"));
        AuLKitchenRadioButton->setGeometry(QRect(0, 40, 117, 22));
        kitchenNoneRadioButton = new QRadioButton(kitchenBox);
        kitchenNoneRadioButton->setObjectName(QStringLiteral("kitchenNoneRadioButton"));
        kitchenNoneRadioButton->setGeometry(QRect(0, 60, 117, 22));
        motionValueStringLabel = new QLabel(centralwidget);
        motionValueStringLabel->setObjectName(QStringLiteral("motionValueStringLabel"));
        motionValueStringLabel->setGeometry(QRect(120, 350, 181, 17));
        damageTabWidget = new QTabWidget(centralwidget);
        damageTabWidget->setObjectName(QStringLiteral("damageTabWidget"));
        damageTabWidget->setGeometry(QRect(280, 400, 221, 121));
        displayBasicTab = new QWidget();
        displayBasicTab->setObjectName(QStringLiteral("displayBasicTab"));
        totalDamageLabel = new QLabel(displayBasicTab);
        totalDamageLabel->setObjectName(QStringLiteral("totalDamageLabel"));
        totalDamageLabel->setGeometry(QRect(0, 0, 94, 17));
        totalDamageFloatLabel = new QLabel(displayBasicTab);
        totalDamageFloatLabel->setObjectName(QStringLiteral("totalDamageFloatLabel"));
        totalDamageFloatLabel->setGeometry(QRect(180, 0, 30, 17));
        rawDamageLabel = new QLabel(displayBasicTab);
        rawDamageLabel->setObjectName(QStringLiteral("rawDamageLabel"));
        rawDamageLabel->setGeometry(QRect(0, 30, 89, 17));
        rawDamageFloatLabel = new QLabel(displayBasicTab);
        rawDamageFloatLabel->setObjectName(QStringLiteral("rawDamageFloatLabel"));
        rawDamageFloatLabel->setGeometry(QRect(180, 30, 30, 17));
        elementalDamageLabel = new QLabel(displayBasicTab);
        elementalDamageLabel->setObjectName(QStringLiteral("elementalDamageLabel"));
        elementalDamageLabel->setGeometry(QRect(0, 60, 81, 17));
        eleDamageFloatLabel = new QLabel(displayBasicTab);
        eleDamageFloatLabel->setObjectName(QStringLiteral("eleDamageFloatLabel"));
        eleDamageFloatLabel->setGeometry(QRect(180, 60, 30, 17));
        damageTabWidget->addTab(displayBasicTab, QString());
        displayAdvancedTab = new QWidget();
        displayAdvancedTab->setObjectName(QStringLiteral("displayAdvancedTab"));
        damageTabWidget->addTab(displayAdvancedTab, QString());
        motionValueListWidget = new QListWidget(centralwidget);
        motionValueListWidget->setObjectName(QStringLiteral("motionValueListWidget"));
        motionValueListWidget->setGeometry(QRect(10, 370, 251, 151));
        gloveBox = new QGroupBox(centralwidget);
        gloveBox->setObjectName(QStringLiteral("gloveBox"));
        gloveBox->setGeometry(QRect(150, 0, 151, 141));
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
        challenger2RadioButton->setGeometry(QRect(0, 80, 117, 22));
        gloveNoneRadioButton = new QRadioButton(gloveBox);
        gloveNoneRadioButton->setObjectName(QStringLiteral("gloveNoneRadioButton"));
        gloveNoneRadioButton->setGeometry(QRect(0, 120, 117, 22));
        peakPerformanceRadioButton = new QRadioButton(gloveBox);
        peakPerformanceRadioButton->setObjectName(QStringLiteral("peakPerformanceRadioButton"));
        peakPerformanceRadioButton->setGeometry(QRect(0, 100, 161, 22));
        criticalEyeBox = new QGroupBox(centralwidget);
        criticalEyeBox->setObjectName(QStringLiteral("criticalEyeBox"));
        criticalEyeBox->setGeometry(QRect(400, 0, 120, 121));
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
        criticalGodRadioButton->setGeometry(QRect(0, 80, 117, 22));
        CENoneRadioButton = new QRadioButton(criticalEyeBox);
        CENoneRadioButton->setObjectName(QStringLiteral("CENoneRadioButton"));
        CENoneRadioButton->setGeometry(QRect(0, 100, 117, 22));
        weapon_type_list_widget = new QListWidget(centralwidget);
        new QListWidgetItem(weapon_type_list_widget);
        new QListWidgetItem(weapon_type_list_widget);
        weapon_type_list_widget->setObjectName(QStringLiteral("weapon_type_list_widget"));
        weapon_type_list_widget->setGeometry(QRect(10, 20, 131, 141));
        dangerBox = new QGroupBox(centralwidget);
        dangerBox->setObjectName(QStringLiteral("dangerBox"));
        dangerBox->setGeometry(QRect(400, 260, 120, 81));
        adrenaline2RadioButton = new QRadioButton(dangerBox);
        adrenaline2RadioButton->setObjectName(QStringLiteral("adrenaline2RadioButton"));
        adrenaline2RadioButton->setGeometry(QRect(0, 20, 117, 22));
        heroicsRadioButton = new QRadioButton(dangerBox);
        heroicsRadioButton->setObjectName(QStringLiteral("heroicsRadioButton"));
        heroicsRadioButton->setGeometry(QRect(0, 40, 117, 22));
        dangerNoneRadioButton = new QRadioButton(dangerBox);
        dangerNoneRadioButton->setObjectName(QStringLiteral("dangerNoneRadioButton"));
        dangerNoneRadioButton->setGeometry(QRect(0, 60, 117, 22));
        huntingHornBox = new QGroupBox(centralwidget);
        huntingHornBox->setObjectName(QStringLiteral("huntingHornBox"));
        huntingHornBox->setGeometry(QRect(530, 170, 120, 141));
        attackUpSRadioButton = new QRadioButton(huntingHornBox);
        attackUpSRadioButton->setObjectName(QStringLiteral("attackUpSRadioButton"));
        attackUpSRadioButton->setGeometry(QRect(0, 20, 117, 22));
        attackUpLRadioButton = new QRadioButton(huntingHornBox);
        attackUpLRadioButton->setObjectName(QStringLiteral("attackUpLRadioButton"));
        attackUpLRadioButton->setGeometry(QRect(0, 40, 117, 22));
        replayCheckBox = new QCheckBox(huntingHornBox);
        replayCheckBox->setObjectName(QStringLiteral("replayCheckBox"));
        replayCheckBox->setGeometry(QRect(0, 100, 97, 22));
        HHNoneRadioButton = new QRadioButton(huntingHornBox);
        HHNoneRadioButton->setObjectName(QStringLiteral("HHNoneRadioButton"));
        HHNoneRadioButton->setGeometry(QRect(0, 120, 71, 22));
        affinityUpCheckBox = new QCheckBox(huntingHornBox);
        affinityUpCheckBox->setObjectName(QStringLiteral("affinityUpCheckBox"));
        affinityUpCheckBox->setGeometry(QRect(0, 60, 111, 22));
        elementUpCheckBox = new QCheckBox(huntingHornBox);
        elementUpCheckBox->setObjectName(QStringLiteral("elementUpCheckBox"));
        elementUpCheckBox->setGeometry(QRect(0, 80, 111, 22));
        seedPillBox = new QGroupBox(centralwidget);
        seedPillBox->setObjectName(QStringLiteral("seedPillBox"));
        seedPillBox->setGeometry(QRect(280, 170, 81, 81));
        mightSeedRadioButton = new QRadioButton(seedPillBox);
        mightSeedRadioButton->setObjectName(QStringLiteral("mightSeedRadioButton"));
        mightSeedRadioButton->setGeometry(QRect(0, 20, 117, 22));
        mightPillRadioButton = new QRadioButton(seedPillBox);
        mightPillRadioButton->setObjectName(QStringLiteral("mightPillRadioButton"));
        mightPillRadioButton->setGeometry(QRect(0, 40, 51, 22));
        mightNoneRadioButton = new QRadioButton(seedPillBox);
        mightNoneRadioButton->setObjectName(QStringLiteral("mightNoneRadioButton"));
        mightNoneRadioButton->setGeometry(QRect(0, 60, 117, 22));
        weaponLabel = new QLabel(centralwidget);
        weaponLabel->setObjectName(QStringLiteral("weaponLabel"));
        weaponLabel->setGeometry(QRect(10, 170, 67, 17));
        AuXBox = new QGroupBox(centralwidget);
        AuXBox->setObjectName(QStringLiteral("AuXBox"));
        AuXBox->setGeometry(QRect(320, 0, 71, 121));
        AuSRadioButton = new QRadioButton(AuXBox);
        AuSRadioButton->setObjectName(QStringLiteral("AuSRadioButton"));
        AuSRadioButton->setGeometry(QRect(0, 20, 71, 22));
        AuMRadioButton = new QRadioButton(AuXBox);
        AuMRadioButton->setObjectName(QStringLiteral("AuMRadioButton"));
        AuMRadioButton->setGeometry(QRect(0, 40, 71, 22));
        AuLRadioButton = new QRadioButton(AuXBox);
        AuLRadioButton->setObjectName(QStringLiteral("AuLRadioButton"));
        AuLRadioButton->setGeometry(QRect(0, 60, 71, 22));
        AuXLRadioButton = new QRadioButton(AuXBox);
        AuXLRadioButton->setObjectName(QStringLiteral("AuXLRadioButton"));
        AuXLRadioButton->setGeometry(QRect(0, 80, 71, 22));
        AuXNoneRadioButton = new QRadioButton(AuXBox);
        AuXNoneRadioButton->setObjectName(QStringLiteral("AuXNoneRadioButton"));
        AuXNoneRadioButton->setGeometry(QRect(0, 100, 71, 22));
        weaponTypeLabel = new QLabel(centralwidget);
        weaponTypeLabel->setObjectName(QStringLiteral("weaponTypeLabel"));
        weaponTypeLabel->setGeometry(QRect(10, 0, 101, 17));
        weapon_list_widget = new QListWidget(centralwidget);
        weapon_list_widget->setObjectName(QStringLiteral("weapon_list_widget"));
        weapon_list_widget->setGeometry(QRect(10, 190, 251, 151));
        elementBox = new QGroupBox(centralwidget);
        elementBox->setObjectName(QStringLiteral("elementBox"));
        elementBox->setGeometry(QRect(530, 0, 131, 121));
        element1RadioButton = new QRadioButton(elementBox);
        element1RadioButton->setObjectName(QStringLiteral("element1RadioButton"));
        element1RadioButton->setGeometry(QRect(0, 20, 117, 22));
        element2RadioButton = new QRadioButton(elementBox);
        element2RadioButton->setObjectName(QStringLiteral("element2RadioButton"));
        element2RadioButton->setGeometry(QRect(0, 40, 117, 22));
        element3RadioButton = new QRadioButton(elementBox);
        element3RadioButton->setObjectName(QStringLiteral("element3RadioButton"));
        element3RadioButton->setGeometry(QRect(0, 60, 117, 22));
        elementAtkUpCheckBox = new QCheckBox(elementBox);
        elementAtkUpCheckBox->setObjectName(QStringLiteral("elementAtkUpCheckBox"));
        elementAtkUpCheckBox->setGeometry(QRect(0, 80, 131, 22));
        elementNoneRadioButton = new QRadioButton(elementBox);
        elementNoneRadioButton->setObjectName(QStringLiteral("elementNoneRadioButton"));
        elementNoneRadioButton->setGeometry(QRect(0, 100, 71, 22));
        fortifyBox = new QGroupBox(centralwidget);
        fortifyBox->setObjectName(QStringLiteral("fortifyBox"));
        fortifyBox->setGeometry(QRect(280, 260, 71, 80));
        faint1RadioButton = new QRadioButton(fortifyBox);
        faint1RadioButton->setObjectName(QStringLiteral("faint1RadioButton"));
        faint1RadioButton->setGeometry(QRect(0, 20, 117, 22));
        faint2RadioButton = new QRadioButton(fortifyBox);
        faint2RadioButton->setObjectName(QStringLiteral("faint2RadioButton"));
        faint2RadioButton->setGeometry(QRect(0, 40, 117, 22));
        fortifyNoneRadioButton = new QRadioButton(fortifyBox);
        fortifyNoneRadioButton->setObjectName(QStringLiteral("fortifyNoneRadioButton"));
        fortifyNoneRadioButton->setGeometry(QRect(0, 60, 117, 22));
        caclulatePushButton = new QPushButton(centralwidget);
        caclulatePushButton->setObjectName(QStringLiteral("caclulatePushButton"));
        caclulatePushButton->setGeometry(QRect(280, 370, 85, 27));
        otherBox = new QGroupBox(centralwidget);
        otherBox->setObjectName(QStringLiteral("otherBox"));
        otherBox->setGeometry(QRect(530, 350, 151, 171));
        sharpnessCheckBox = new QCheckBox(otherBox);
        sharpnessCheckBox->setObjectName(QStringLiteral("sharpnessCheckBox"));
        sharpnessCheckBox->setGeometry(QRect(0, 20, 111, 22));
        weaknessExploitCheckBox = new QCheckBox(otherBox);
        weaknessExploitCheckBox->setObjectName(QStringLiteral("weaknessExploitCheckBox"));
        weaknessExploitCheckBox->setGeometry(QRect(0, 40, 151, 22));
        powerCharmCheckBox = new QCheckBox(otherBox);
        powerCharmCheckBox->setObjectName(QStringLiteral("powerCharmCheckBox"));
        powerCharmCheckBox->setGeometry(QRect(0, 80, 121, 22));
        criticalDrawCheckBox = new QCheckBox(otherBox);
        criticalDrawCheckBox->setObjectName(QStringLiteral("criticalDrawCheckBox"));
        criticalDrawCheckBox->setGeometry(QRect(0, 60, 121, 22));
        powerTalonCheckBox = new QCheckBox(otherBox);
        powerTalonCheckBox->setObjectName(QStringLiteral("powerTalonCheckBox"));
        powerTalonCheckBox->setGeometry(QRect(0, 100, 111, 22));
        checkBox = new QCheckBox(otherBox);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(0, 120, 101, 22));
        checkBox_2 = new QCheckBox(otherBox);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setGeometry(QRect(0, 140, 141, 22));
        motionValueLabel = new QLabel(centralwidget);
        motionValueLabel->setObjectName(QStringLiteral("motionValueLabel"));
        motionValueLabel->setGeometry(QRect(10, 350, 101, 17));
        testwindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(testwindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 682, 25));
        testwindow->setMenuBar(menubar);
        statusbar = new QStatusBar(testwindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        testwindow->setStatusBar(statusbar);

        retranslateUi(testwindow);

        damageTabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(testwindow);
    } // setupUi

    void retranslateUi(QMainWindow *testwindow)
    {
        testwindow->setWindowTitle(QApplication::translate("testwindow", "MainWindow", 0));
        kitchenBox->setTitle(QApplication::translate("testwindow", "Kitchen", 0));
        AuSKitchenRadioButton->setText(QApplication::translate("testwindow", "Attack Up S", 0));
        AuLKitchenRadioButton->setText(QApplication::translate("testwindow", "Attack Up L", 0));
        kitchenNoneRadioButton->setText(QApplication::translate("testwindow", "None", 0));
        motionValueStringLabel->setText(QApplication::translate("testwindow", "[0]", 0));
        totalDamageLabel->setText(QApplication::translate("testwindow", "Total Damage", 0));
        totalDamageFloatLabel->setText(QApplication::translate("testwindow", "0.00", 0));
        rawDamageLabel->setText(QApplication::translate("testwindow", "Raw Damage", 0));
        rawDamageFloatLabel->setText(QApplication::translate("testwindow", "0.00", 0));
        elementalDamageLabel->setText(QApplication::translate("testwindow", "Ele Damage", 0));
        eleDamageFloatLabel->setText(QApplication::translate("testwindow", "0.00", 0));
        damageTabWidget->setTabText(damageTabWidget->indexOf(displayBasicTab), QApplication::translate("testwindow", "Tab 1", 0));
        damageTabWidget->setTabText(damageTabWidget->indexOf(displayAdvancedTab), QApplication::translate("testwindow", "Tab 2", 0));
        gloveBox->setTitle(QApplication::translate("testwindow", "Glove", 0));
        latentPower1RadioButton->setText(QApplication::translate("testwindow", "Latent Power+1", 0));
        latentPower2RadioButton->setText(QApplication::translate("testwindow", "Latent Power+2", 0));
        challenger1RadioButton->setText(QApplication::translate("testwindow", "Challenger+1", 0));
        challenger2RadioButton->setText(QApplication::translate("testwindow", "Challenger+2", 0));
        gloveNoneRadioButton->setText(QApplication::translate("testwindow", "None", 0));
        peakPerformanceRadioButton->setText(QApplication::translate("testwindow", "Peak Performance", 0));
        criticalEyeBox->setTitle(QApplication::translate("testwindow", "Critical Eye", 0));
        criticalEye1RadioButton->setText(QApplication::translate("testwindow", "Critical Eye+1", 0));
        criticalEye2RadioButton->setText(QApplication::translate("testwindow", "Critical Eye+2", 0));
        criticalEye3RadioButton->setText(QApplication::translate("testwindow", "Critical Eye+3", 0));
        criticalGodRadioButton->setText(QApplication::translate("testwindow", "Critical God", 0));
        CENoneRadioButton->setText(QApplication::translate("testwindow", "None", 0));

        const bool __sortingEnabled = weapon_type_list_widget->isSortingEnabled();
        weapon_type_list_widget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = weapon_type_list_widget->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("testwindow", "ChargeBlades", 0));
        QListWidgetItem *___qlistwidgetitem1 = weapon_type_list_widget->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("testwindow", "InsectGlaives", 0));
        weapon_type_list_widget->setSortingEnabled(__sortingEnabled);

        dangerBox->setTitle(QApplication::translate("testwindow", "Danger", 0));
        adrenaline2RadioButton->setText(QApplication::translate("testwindow", "Adrenaline+2", 0));
        heroicsRadioButton->setText(QApplication::translate("testwindow", "Heroics", 0));
        dangerNoneRadioButton->setText(QApplication::translate("testwindow", "None", 0));
        huntingHornBox->setTitle(QApplication::translate("testwindow", "Hunting Horn", 0));
        attackUpSRadioButton->setText(QApplication::translate("testwindow", "Attack Up (S)", 0));
        attackUpLRadioButton->setText(QApplication::translate("testwindow", "Attack Up (L)", 0));
        replayCheckBox->setText(QApplication::translate("testwindow", "Replay", 0));
        HHNoneRadioButton->setText(QApplication::translate("testwindow", "None", 0));
        affinityUpCheckBox->setText(QApplication::translate("testwindow", "Affinity Up", 0));
        elementUpCheckBox->setText(QApplication::translate("testwindow", "Element Up", 0));
        seedPillBox->setTitle(QApplication::translate("testwindow", "Might Item", 0));
        mightSeedRadioButton->setText(QApplication::translate("testwindow", "Seed", 0));
        mightPillRadioButton->setText(QApplication::translate("testwindow", "Pill", 0));
        mightNoneRadioButton->setText(QApplication::translate("testwindow", "None", 0));
        weaponLabel->setText(QApplication::translate("testwindow", "Weapon", 0));
        AuXBox->setTitle(QApplication::translate("testwindow", "AuX", 0));
        AuSRadioButton->setText(QApplication::translate("testwindow", "AuS", 0));
        AuMRadioButton->setText(QApplication::translate("testwindow", "AuM", 0));
        AuLRadioButton->setText(QApplication::translate("testwindow", "AuL", 0));
        AuXLRadioButton->setText(QApplication::translate("testwindow", "AuXL", 0));
        AuXNoneRadioButton->setText(QApplication::translate("testwindow", "None", 0));
        weaponTypeLabel->setText(QApplication::translate("testwindow", "Weapon Type", 0));
        elementBox->setTitle(QApplication::translate("testwindow", "Element", 0));
        element1RadioButton->setText(QApplication::translate("testwindow", "Element+1", 0));
        element2RadioButton->setText(QApplication::translate("testwindow", "Element+2", 0));
        element3RadioButton->setText(QApplication::translate("testwindow", "Element+3", 0));
        elementAtkUpCheckBox->setText(QApplication::translate("testwindow", "ElementAtkUp", 0));
        elementNoneRadioButton->setText(QApplication::translate("testwindow", "None", 0));
        fortifyBox->setTitle(QApplication::translate("testwindow", "Fortify", 0));
        faint1RadioButton->setText(QApplication::translate("testwindow", "Cartx1", 0));
        faint2RadioButton->setText(QApplication::translate("testwindow", "Cartx2", 0));
        fortifyNoneRadioButton->setText(QApplication::translate("testwindow", "None", 0));
        caclulatePushButton->setText(QApplication::translate("testwindow", "Calculate", 0));
        otherBox->setTitle(QApplication::translate("testwindow", "Other", 0));
        sharpnessCheckBox->setText(QApplication::translate("testwindow", "Sharpness+1", 0));
        weaknessExploitCheckBox->setText(QApplication::translate("testwindow", "Weakness Exploit", 0));
        powerCharmCheckBox->setText(QApplication::translate("testwindow", "Power Charm", 0));
        criticalDrawCheckBox->setText(QApplication::translate("testwindow", "Critical Draw", 0));
        powerTalonCheckBox->setText(QApplication::translate("testwindow", "Power Talon", 0));
        checkBox->setText(QApplication::translate("testwindow", "Raw Hone", 0));
        checkBox_2->setText(QApplication::translate("testwindow", "Critical Element", 0));
        motionValueLabel->setText(QApplication::translate("testwindow", "Motion Value", 0));
    } // retranslateUi

};

namespace Ui {
    class testwindow: public Ui_testwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTWINDOW_H
