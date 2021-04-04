#pragma once
#include <string>
#include <vector>
#include <unordered_map>

namespace sarah {
class EnemyType {
public:
    enum class Ability { UNKNOWN, STR, DEX, CON, INT, WIS, CHA };
    struct Attack {
        std::string name;
        std::string description;
        Ability modifier;
        int num_dice;
        int dice_sides;
    };

    EnemyType(const std::string& type_name, const std::string&  creature_class) : type_name_(type_name), creature_class_(creature_class) {}
    void AddAttack(const std::string&  name, const std::string&  description, Ability modifier, int num_dice, int dice_sides);
    void SetHPDice(int num_dice, int dice_sides) {
        num_hp_dice_ = num_dice;
        hp_dice_sides_ = dice_sides;
    }
    void SetAbilityMod(Ability ability, int mod_value) {
        ability_mods_[ability] = mod_value;
    }

    // Functions for printing out an EnemyType in a structured way.
    std::string Name() const { return type_name_; }
    std::string CreatureClass() const { return creature_class_; }
    std::string Attacks() const;
    std::string Hp() const;
    std::string Skills() const;

    static std::string AbilityToString(Ability ability);

private:
    std::string type_name_;
    std::string creature_class_;
    int num_hp_dice_;
    int hp_dice_sides_;
    std::vector<Attack> attacks_;
    // Map from ability type to modifier.
    std::unordered_map<Ability, int> ability_mods_;
};
}