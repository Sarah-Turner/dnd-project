#include "enemy_type.h"
#include <sstream>

namespace sarah {
void EnemyType::AddAttack(const std::string&  name, const std::string&  description, Ability modifier, int num_dice, int dice_sides) {
    EnemyType::Attack attack {name, description, modifier, num_dice, dice_sides};
    attacks_.push_back(attack);
}
std::string EnemyType::Attacks() {
    std::ostringstream oss;
    for (const auto& attack : attacks_) {
        oss << attack.name << std::endl << attack.description << std::endl << "Damage: " << attack.num_dice << 'd' << attack.dice_sides << '+' << ability_mods_[attack.modifier];
    }
    return oss.str();
}
std::string EnemyType::Hp() {
    std::ostringstream oss;
    oss << num_hp_dice_ << 'd' << hp_dice_sides_;
    return oss.str();
}
std::string EnemyType::Skills() {
    std::ostringstream oss;
    for (const auto& ability_mod_pair : ability_mods_) {
        oss << AbilityToString(ability_mod_pair.first) << ": " << ability_mod_pair.second << std::endl;
    }
    return oss.str();
}

std::string EnemyType::AbilityToString(EnemyType::Ability ability) {
    switch(ability) {
        case EnemyType::Ability::STR: return "STR";
        case EnemyType::Ability::DEX: return "DEX";
        case EnemyType::Ability::CON: return "CON";
        case EnemyType::Ability::INT: return "INT";
        case EnemyType::Ability::WIS: return "WIS";
        case EnemyType::Ability::CHA: return "CHA";
    }
}
}