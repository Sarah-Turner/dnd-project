int main() {
    char response;
    do
    {
        std::cout << "1. Create Enemy Type" << endl;
        std::cout << "2. List Created Types" << endl;
        std::cout << "3. Generate Enemy From Type" << endl;
        std::cout << "4. List Generated Enemies" << endl;
        std::cout << "5. Exit" << endl;
        std::cout << "Enter Choice: ";
        std::cin >> response;
    } while (response < 1 || response > 5)

    switch (response)
    {
        
    }
    return 0;
}