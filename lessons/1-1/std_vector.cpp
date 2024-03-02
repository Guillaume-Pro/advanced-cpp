#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers; // Crée un vector vide

    // Ajoute des éléments
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);

    // Accès et affichage des éléments
    for (int i = 0; i < numbers.size(); ++i) {
        std::cout << numbers[i] << " "; // Affiche chaque élément
    }
    std::cout << std::endl;

    // Utilisation d'un itérateur pour parcourir le vector
    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << *it << " "; // Affiche chaque élément
    }
    std::cout << std::endl;

    return 0;
}
