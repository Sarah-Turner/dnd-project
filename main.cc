#include <iostream>

void CreateEnemyType() {

}

void ListCreatedTypes() {

}

void GenerateEnemy() {

}

void ListEnemies() {

}

int main() {
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
                CreateEnemyType();
                break; 
            case 2:
                ListCreatedTypes();
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
    std::cout << "Goodbye!" std::endl;
    return 0;
}