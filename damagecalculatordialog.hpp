#ifndef DAMAGECALCULATORDIALOG_HPP
#define DAMAGECALCULATORDIALOG_HPP

#include <QDialog>
#include <QtSql/QSqlQuery>
#include <QString>
#include <vector>

namespace Ui {
class damagecalculatordialog;
}

class damagecalculatordialog : public QDialog
{
    Q_OBJECT

public:
    explicit damagecalculatordialog(QWidget *parent = 0);
    ~damagecalculatordialog();

private slots:
    QSqlQuery createAndRunSpecificQuery(const QString& selectSQL);

    void on_weapon_type_list_widget_clicked(const QModelIndex &index);

    void on_weapon_list_widget_clicked(const QModelIndex &index);

    void on_HHNoneRadioButton_clicked();

    void on_attackUpSRadioButton_clicked();

    void on_attackUpLRadioButton_clicked();

    void on_caclulatePushButton_clicked();

    void on_affinityUpCheckBox_clicked();

    void on_elementUpCheckBox_clicked();

    void on_motionValueListWidget_clicked(const QModelIndex &index);

private:
    Ui::damagecalculatordialog *ui;
    QString weapon;
    QString weaponType;
    QString motionValue;
};

#endif // DAMAGECALCULATORDIALOG_HPP
