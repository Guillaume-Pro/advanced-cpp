#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, int> ages; // Crée un map avec des clés de type string et des valeurs de type int

    // Ajout d'éléments
    ages["Alice"] = 30;
    ages["Bob"] = 25;
    ages["Charlie"] = 35;

    // Accès et affichage d'un élément
    std::cout << "L'âge de Bob est " << ages["Bob"] << " ans." << std::endl; // Affiche l'âge de Bob

    // Parcours de tous les éléments
    for (const auto& pair : ages) {
        std::cout << pair.first << " a " << pair.second << " ans." << std::endl; // Affiche le nom et l'âge
    }

    return 0;
}
