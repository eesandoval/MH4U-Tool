#include <QtSql/QSqlQuery>
#include "src/Headers/damagecalculator.hpp"

float calculate_raw_sharpness(std::string sharpness)
{
    float result;
    if (sharpness == "Purple")
        result = 1.45;
    else if (sharpness == "White")
        result = 1.32;
    else if (sharpness == "Blue")
        result = 1.20;
    else if (sharpness == "Green")
        result = 1.05;
    else if (sharpness == "Yellow")
        result = 1.00;
    else if (sharpness == "Orange")
        result = 0.75;
    else if (sharpness == "Red")
        result = 0.50;
    else
        exit(1);
    return result;
}

float calculate_ele_sharpness(std::string sharpness)
{
    float result;
    if (sharpness == "Purple")
        result = 1.20;
    else if (sharpness == "White")
        result = 1.12;
    else if (sharpness == "Blue")
        result = 1.06;
    else if (sharpness == "Green")
        result = 1.00;
    else if (sharpness == "Yellow")
        result = 0.75;
    else if (sharpness == "Orange")
        result = 0.50;
    else if (sharpness == "Red")
        result = 0.25;
    else
        exit(1);
    return result;
}

float calculate_raw(std::map<std::string, float> modifiers, std::string weapon_type)
{
    float weapon_modifier;
    float result;

    if (weapon_type == "SwitchAxes")
        weapon_modifier = 5.4;
    else if (weapon_type == "Hammers" || weapon_type == "HuntingHorns")
        weapon_modifier = 5.2;
    else if (weapon_type == "GreatSwords")
        weapon_modifier = 4.2;
    else if (weapon_type == "ChargeBlades")
        weapon_modifier = 3.6;
    else if (weapon_type == "LongSwords")
        weapon_modifier = 3.3;
    else if (weapon_type == "InsectGlaives")
        weapon_modifier = 3.1;
    else if (weapon_type == "Lances" || weapon_type == "Gunlances")
        weapon_modifier = 2.3;
    else if (weapon_type == "HeavyBowguns")
        weapon_modifier = 1.5;
    else if (weapon_type == "SwordnShields" || weapon_type == "DualBlades")
        weapon_modifier = 1.4;
    else if (weapon_type == "LightBowguns")
        weapon_modifier = 1.3;
    else if (weapon_type == "Bows")
        weapon_modifier = 1.2;

    result = modifiers["attack"]/weapon_modifier;
    result += modifiers["hone"];
    result += modifiers["AuX"];
    result += modifiers["kitchen"];
    result += modifiers["seed"];
    result += modifiers["glove"];
    result += modifiers["powerCharm"] + modifiers["powerTalon"];
    result *= (modifiers["HH"] + modifiers["replay"]);
    result *= modifiers["danger"];
    result *= modifiers["fortify"];
    result *= modifiers["weaponSpecific"];
    result *= modifiers["artillery"];
    result *= modifiers["wystone"];

    return result;
}
//asdasdad

float calculate_ele(std::map<std::string, float> modifiers)
{
    float result;
    float element_multiplier = 1;

    result = modifiers["specialAttack"]/10;
    result += modifiers["elementAdd"]/10;
    element_multiplier *= modifiers["elementMul"];
    element_multiplier *= (modifiers["elementUp"] + modifiers["replay"]);
    element_multiplier *= modifiers["elementAtkUp"];
    if (element_multiplier > 1.2)
        element_multiplier = 1.2;
    result *= element_multiplier;
    result *= modifiers["wystone"];

    return result;
}

float calculate_affinity(std::map<std::string, float> modifiers)
{
    float result;

    result = modifiers["affinity"];
    result += modifiers["criticalEye"];
    result += modifiers["glove"];
    result += modifiers["criticalDraw"];
    result += modifiers["affinityUp"];
    result += modifiers["replay"];
    if (result > 1)
        result = 1;

    return result;
}

float calculate_raw_hitzone(bool weaknessExploit, float rawHitzone)
{
    float result;

    result = rawHitzone;
    if (result >= 0.44 && weaknessExploit)
        result += 0.05;

    return result;
}

float calculate_ele_hitzone(float ele_hitzone)
{
    float result;

    result = ele_hitzone;

    return result;
}

float calculate_weapon_affinity_multiplier(std::string weapon_type)
{
    float result;

    if (weapon_type == "GreatSwords")
        result = 0.2;
    else if (weapon_type == "SwordnShields" || weapon_type == "DualBlades" || weapon_type == "Bows")
        result = 0.35;
    else
        result = 0.25;

    return result;
}

float calculateEleAffinity(bool critElement, std::map<std::string, float> modifiers)
{
    float result;
    float affinity;

    affinity = calculate_affinity(modifiers);

    if (critElement)
        result = (1 + 0.25 * affinity);
    else
        result = 1;

    return result;
}

float calculate_raw_damage(bool weaknessExploit, std::string sharpness, std::string weaponType, float rawHitzone,
                           float motionValue, std::map<std::string, std::map<std::string, float> > all_modifiers)
{
    float rawSharpnessModifier;
    float trueAffinity;
    float trueRaw;
    float trueRawHitzone;
    float trueAffinityMultiplier;
    float rawDamage;
    float trueMotionValue;

    rawSharpnessModifier = calculate_raw_sharpness(sharpness);
    trueAffinity = calculate_affinity(all_modifiers["affinityModifiers"]);
    trueRaw = calculate_raw(all_modifiers["rawModifiers"], weaponType);
    trueRawHitzone = calculate_raw_hitzone(weaknessExploit, rawHitzone);
    trueAffinityMultiplier = calculate_weapon_affinity_multiplier(weaponType);
    trueMotionValue = motionValue/100;

    rawDamage = trueRaw*(1+trueAffinityMultiplier*trueAffinity)*trueMotionValue*trueRawHitzone*rawSharpnessModifier;

    return rawDamage;
}

float calculate_ele_damage(std::string sharpness, std::map<std::string, std::map<std::string, float> > all_modifiers,
                           float ele_hitzone, bool critElement)
{
    float ele_sharpness_modifier;
    float true_ele;
    float true_ele_hitzone;
    float eleDamage;
    float eleAffinity;

    ele_sharpness_modifier = calculate_ele_sharpness(sharpness);

    true_ele = calculate_ele(all_modifiers["eleModifiers"]);
    true_ele_hitzone = calculate_ele_hitzone(ele_hitzone);

    eleAffinity = calculateEleAffinity(critElement, all_modifiers["affinityModifiers"]);

    eleDamage = true_ele * true_ele_hitzone * ele_sharpness_modifier * eleAffinity;

    return eleDamage;
}
