#ifndef DEFENSECALCULATORWINDOW_HPP
#define DEFENSECALCULATORWINDOW_HPP

#include <QMainWindow>

#define MAX_ARMOR_DEF 200

namespace Ui {
class defensecalculatorwindow;
}

class defensecalculatorwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit defensecalculatorwindow(QWidget *parent = 0);
    ~defensecalculatorwindow();

private slots:
    void on_calculate_push_button_clicked();

    void change_displayed_defense();

    void update_total_defense();

    void on_armor_torso_valueChanged(int arg1);

    void on_armor_helmet_valueChanged(int arg1);

    void on_armor_gloves_valueChanged(int arg1);

    void on_armor_waist_valueChanged(int arg1);

    void on_armor_boots_valueChanged(int arg1);

    void on_defense_up_skill_small_toggled(bool checked);

    void on_defense_up_skill_medium_toggled(bool checked);

    void on_defense_up_skill_large_toggled(bool checked);

    void on_defense_up_skill_extra_large_toggled(bool checked);

    void on_hunting_horn_small_toggled(bool checked);

    void on_hunting_horn_large_toggled(bool checked);

    void on_hunting_horn_replay_toggled(bool checked);

    void on_hunting_horn_none_toggled(bool checked);

    void on_defense_up_kitchen_small_toggled(bool checked);

    void on_defense_up_kitchen_large_toggled(bool checked);

    void on_fortify_cart1_toggled(bool checked);

    void on_fortify_cart2_toggled(bool checked);

private:
    Ui::defensecalculatorwindow *ui;
    int total_defense, helmet, torso, waist, gloves, boots, defense_skill_add, kitchen_add;
    float defense_skill_mult, hunting_horn_mult, fortify_mult;
};

#endif // DEFENSECALCULATORWINDOW_HPP
