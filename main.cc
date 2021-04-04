#include <iostream>
#include <vector>
#include "enemy_type.h"
#include "dice.h"

void CreateEnemyType(std::vector<sarah::EnemyType>& enemy_types) {
    std::string name, enemy_class;
    std::cout << "Creating a new enemy type: " << std::endl << "Enter the type name (Ex: Bandit Captain): ";
    std::getline(std::cin, name);
    std::cout << std::endl;
    std::cout << "Enter the class of enemy (Ex: Humanoid, Elemental, Beast, etc): ";
    std:: cin >> enemy_class;
    std::cout << std::endl;
    sarah::EnemyType enemy_type(name, enemy_class);

    int num_dice, dice_sides;
    std::cout << "Enter number of HP dice for this type: ";
    std::cin >> num_dice;
    std::cout << std::endl << "Enter the number of sides for each HP dice: ";
    std::cin >> dice_sides;
    std::cout << std::endl;
    enemy_type.SetHPDice(num_dice, dice_sides);

    int mod;
    std::cout << "Enter the STR modifer for enemy type: ";
    std::cin >> mod;
    std::cout << std::endl;
    enemy_type.SetAbilityMod(sarah::EnemyType::Ability::STR, mod);
    std::cout << "Enter the DEX modifer for enemy type: ";
    std::cin >> mod;
    std::cout << std::endl;
    enemy_type.SetAbilityMod(sarah::EnemyType::Ability::DEX, mod);
    std::cout << "Enter the CON modifer for enemy type: ";
    std::cin >> mod;
    std::cout << std::endl;
    enemy_type.SetAbilityMod(sarah::EnemyType::Ability::CON, mod);
    std::cout << "Enter the INT modifer for enemy type: ";
    std::cin >> mod;
    std::cout << std::endl;
    enemy_type.SetAbilityMod(sarah::EnemyType::Ability::INT, mod);
    std::cout << "Enter the WIS modifer for enemy type: ";
    std::cin >> mod;
    std::cout << std::endl;
    enemy_type.SetAbilityMod(sarah::EnemyType::Ability::WIS, mod);
    std::cout << "Enter the CHA modifer for enemy type: ";
    std::cin >> mod;
    std::cout << std::endl;
    enemy_type.SetAbilityMod(sarah::EnemyType::Ability::CHA, mod);

    char add_more_attacks = 'y';
    std::cout << "Adding enemy type attack(s): " << std::endl;
    while (add_more_attacks == 'y') {
        std::string desc;
        char modifier;
        std::cout << "Enter attack name (Ex: Bite, Scratch, 1H Scimitar Attack): ";
        std::getline(std::cin, name);
        std::cout << std::endl << "(Optionally) Enter a description for the attack (Ex: the enemy swings their scimitar at you): ";
        std::getline(std::cin, desc);
        std::cout << std::endl << "Enter the number of dice used for this attacks damage: ";
        std::cin >> num_dice;
        std::cout << std::endl << "Enter the number of sides for each attack dice: ";
        std::cin >> dice_sides;
        std::cout << std::endl << "Pick an ability modifier used for this attack. (S)tr, (D)ex, (C)on, (I)nt, (W)is, Ch(a), (N)one: ";
        std::cin >> modifier;
        sarah::EnemyType::Ability ability;
        switch (std::toupper(modifier)) {
            case 'S': ability = sarah::EnemyType::Ability::STR; break;
            case 'D': ability = sarah::EnemyType::Ability::DEX; break;
            case 'C': ability = sarah::EnemyType::Ability::CON; break;
            case 'I': ability = sarah::EnemyType::Ability::INT; break;
            case 'W': ability = sarah::EnemyType::Ability::WIS; break;
            case 'A': ability = sarah::EnemyType::Ability::CHA; break;
            default: ability = sarah::EnemyType::Ability::UNKNOWN; break;
        }
        enemy_type.AddAttack(name, desc, ability, num_dice, dice_sides);
        std::cout << std::endl << "Add another attack? (y|n): ";
        std::cin >> add_more_attacks;
    }

    enemy_types.push_back(enemy_type);
}

void ListCreatedTypes(const std::vector<sarah::EnemyType>& enemy_types) {

}

void GenerateEnemy() {

}

void ListEnemies() {

}

int main() {
    std::vector<sarah::EnemyType> enemy_types;
    char response = 0;
    while (response != 5) {
        std::cout << "1. Create Enemy Type" << std::endl;
        std::cout << "2. List Created Types" << std::endl;
        std::cout << "3. Generate Enemy From Type" << std::endl;
        std::cout << "4. List Generated Enemies" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Enter Choice: ";
        std::cin >> response;
        switch (response)
        {
            case 1:
                CreateEnemyType(enemy_types);
                break; 
            case 2:
                ListCreatedTypes(enemy_types);
                break;
            case 3:
                GenerateEnemy();
                break;
            case 4:
                ListEnemies();
                break;
            default:
                break;
        }
    } 
    std::cout << "Goodbye!" << std::endl;
    return 0;
}