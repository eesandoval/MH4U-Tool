#ifndef WEAPON_H
#define WEAPON_H
#include <QString>

class weapon
{
public:
    weapon();

    weapon(QString n, QString wt, int r, int a, QString s, int sp,
           float aff, int def, int sl, QString sh, QString sh1,
           QString s2 = "", int sp2 = 0);

    QString name;
    QString weapon_type;
    int rarity;
    int attack;
    QString special;
    int special_attack;
    QString special2;
    int special_attack2;
    float affinity;
    int defense;
    int num_slots;
    QString sharpness;
    QString sharpness1;
};

#endif // WEAPON_H
