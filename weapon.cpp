#include "weapon.hpp"

weapon::weapon()
{
    name = "";
    weapon_type = "";
    attack = 0;
    rarity = 0;
    affinity = 0;
    special = "";
    special_attack = 0;
    affinity = 0;
    defense = 0;
    num_slots = 0;
    sharpness = "";
    sharpness1 = "";
    special2 = "";
    special_attack2 = 0;
}

weapon::weapon(QString n, QString wt, int r, int a, QString s, int sp,
       float aff, int def, int sl, QString sh, QString sh1,
       QString s2, int sp2)
{
    name = n;
    weapon_type = wt;
    attack = a;
    rarity = r;
    affinity = a;
    special = s;
    special_attack = sp;
    affinity = aff;
    defense = def;
    num_slots = sl;
    sharpness =  sh;
    sharpness1 = sh1;
    special2 = s2;
    special_attack2 = sp2;
}

