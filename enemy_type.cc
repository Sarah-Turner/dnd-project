#include "enemy_type.h"
#include <sstream>

namespace sarah {
void EnemyType::AddAttack(const std::string&  name, const std::string&  description, Ability modifier, int num_dice, int dice_sides) {
    EnemyType::Attack attack {name, description, modifier, num_dice, dice_sides};
    attacks_.push_back(attack);
}
std::string EnemyType::Attacks() const {
    std::ostringstream oss;
    for (const auto& attack : attacks_) {
        oss << attack.name << " (" << attack.description << ") - Damage: " << attack.num_dice << 'd' << attack.dice_sides;
        if (!(attack.modifier == EnemyType::Ability::UNKNOWN)) {
            oss << '+' << ability_mods_.at(attack.modifier);
        }
        oss << std::endl;
    }
    return oss.str();
}
std::string EnemyType::Hp() const {
    std::ostringstream oss;
    oss << num_hp_dice_ << 'd' << hp_dice_sides_;
    return oss.str();
}
std::string EnemyType::Skills() const {
    std::ostringstream oss;
    for (const auto& ability_mod_pair : ability_mods_) {
        oss << AbilityToString(ability_mod_pair.first) << ": " << ability_mod_pair.second << std::endl;
    }
    return oss.str();
}

std::string EnemyType::AbilityToString(EnemyType::Ability ability) {
    switch(ability) {
        case EnemyType::Ability::UNKNOWN: return "UNKNOWN";
        case EnemyType::Ability::STR: return "STR";
        case EnemyType::Ability::DEX: return "DEX";
        case EnemyType::Ability::CON: return "CON";
        case EnemyType::Ability::INT: return "INT";
        case EnemyType::Ability::WIS: return "WIS";
        case EnemyType::Ability::CHA: return "CHA";
    }
    return "UNKNOWN";
}
}