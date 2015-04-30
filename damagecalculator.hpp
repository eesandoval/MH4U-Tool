#ifndef DAMAGECALCULATOR_HPP
#define DAMAGECALCULATOR_HPP
#include <map>
#include <string>

float calculate_raw_sharpness(std::string sharpness);

float calculate_ele_sharpness(std::string sharpness);

float calculate_raw(std::map<std::string, float> modifiers, std::string weapon_type);

float calculate_ele(std::map<std::string, float> modifiers);

float calculate_affinity(std::map<std::string, float> modifiers);

float calculate_raw_hitzone(std::map<std::string, float> modifiers, float raw_hitzone);

float calculate_ele_hitzone(float ele_hitzone);

float calculate_weapon_affinity_multiplier(std::string weapon_type);

float calculate_raw_damage(bool weaknessExploit, std::string sharpness, std::string weaponType, float rawHitzone,
                           float motionValue, std::map<std::string, std::map<std::string, float> > all_modifiers);

float calculate_ele_damage(std::string sharpness, std::map<std::string, std::map<std::string, float> > all_modifiers,
                           float ele_hitzone);

#endif // DAMAGECALCULATOR_HPP
