#include "enemy_type.h"
namespace sarah
{
    std::string EnemyType::Attacks()
    {
        std::ostringstream oss;
        int attack_mod = std::max(ability_mods_[EnemyType::Ability::STR], ability_mods_[EnemyType::Ability::DEX]);
        oss << attack_name_ << ": " << num_attack_dice_ << 'd' << attack_dice_sides_ << '+' << attack_mod;
        return oss.str();
    }
    std::string EnemyType::Hp()
    {
        std::ostringstream oss;
        oss << num_hp_dice << 'd' << hp_dice_sides_;
        return oss.str();
    }
    std::string EnemyType::Skills()
    {
        std::ostringstream oss;
        oss << "STR: " << str_mod_ << ", DEX: " << dex_mod_ << ", CON: " << con_mod_ << ", INT: " << int_mod_ << ", WIS: " << wis_mod_ << ", CHA: " << cha_mod_;
        return oss.str();
    }
}