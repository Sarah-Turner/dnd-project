#include <string>

namespace {
class EnemyType {
    public:
        std::string Name();
        std::string CreatureClass();
        std::string Attack();
        std::string Hp();
        std::string Skills();
    private:
        std::string type_name_;
        std::string creature_class_;
        int num_hp_dice_;
        int hp_dice_sides_;
        std::string attack_name_;
        int num_attack_dice_;
        int attack_dice_sides_;
        int str_mod;
        int dex_mod;
        int con_mod;
        int int_mod;
        int wis_mod;
        int cha_mod;
};
}