#pragma
#include <string>
#include <iostream>
#include <vector>

namespace sarah
{
    class EnemyType
    {
    public:
        enum class Ability
        {
            STR,
            DEX,
            CON,
            INT,
            WIS,
            CHA
        };
        struct Attack
        {
            std::string name;
            std::string description;
            Ability modifier;
            int num_dice;
            int dice_sides;
        };
        EnemyType(std::string type_name, std::string creature_class) : type_name_(type_name), creature_class_(creature_class) {}
        void AddAttack(std::string name, std::string description, Ability modifier, int numb_dice, int dice_sides);
        void SetHPDice(int num_dice, int dice_sides) {
            num_hp_dice_ = num_dice;
            hp_dice_sides_ = dice_sides;
        }
        void SetAbilityMod(Ability ability, int mod_value) {
            ability_mods[ability] = mod_value;
        }
        std::string Name() { return type_name_; }
        std::string CreatureClass() { return creature_class_; }
        std::string Attacks();
        std::string Hp();
        std::string Skills();

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