#include "addweapondialog.hpp"
#include "ui_addweapondialog.h"

addweapondialog::addweapondialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addweapondialog)
{
    ui->setupUi(this);

    // Set up the spin boxes
    ui->elementSpinBox->setMaximum(2000);
    ui->elementSpinBox->setMinimum(0);
    ui->attackSpinBox->setMaximum(2000);
    ui->attackSpinBox->setMinimum(0);
    ui->affinityDoubleSpinBox->setMaximum(1.00);
    ui->affinityDoubleSpinBox->setMinimum(0.00);
}

addweapondialog::~addweapondialog()
{
    delete ui;
}

void addweapondialog::on_buttonBox_accepted()
{
    std::ofstream outFile;
    outFile.open("MH4U-Tool-Custom-Weapons.txt", std::ios_base::app);
    outFile << ui->nameLineEdit->text().toStdString() << "\n";
    outFile << ui->weaponTypeComboBox->currentText().toStdString() << "\n";
    outFile << ui->attackSpinBox->value() << "\n";
    outFile << ui->elementTypeComboBox->currentText().toStdString() << "\n";
    outFile << ui->elementSpinBox->value() << "\n";
    outFile << ui->affinityDoubleSpinBox->value() << "\n";
    outFile << ui->sharpnessButtonBox->currentText().toStdString() << "\n";
    outFile << ui->sharpness1ComboBox->currentText().toStdString() << "\n";
    outFile << "---END---\n";
    outFile.close();
}
