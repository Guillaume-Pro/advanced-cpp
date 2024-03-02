#include <iostream>
#include <any>
#include <string>

int main() {
    std::any variable;

    variable = 10; // Stocke un entier
    std::cout << std::any_cast<int>(variable) << std::endl; // Extraire en tant qu'int

    variable = std::string("Hello World"); // Change pour stocker un string
    std::cout << std::any_cast<std::string>(variable) << std::endl; // Extraire en tant que string

    try {
        std::any_cast<float>(variable); // Essaie d'extraire un float (échouera)
    } catch (const std::bad_any_cast& e) {
        std::cout << "Error: " << e.what() << std::endl; // Affiche le message d'erreur
    }

    return 0;
}
