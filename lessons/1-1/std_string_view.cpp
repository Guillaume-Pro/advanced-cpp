#include <iostream>
#include <string>
#include <string_view>

// std::string_view fournit une manière légère et sûre de se référer à une séquence
// de caractères sans copier ces caractères
// https://en.cppreference.com/w/cpp/string/basic_string_view

void Afficher(std::string_view sv) {
    std::cout << sv << std::endl; // Affiche la vue sur la chaîne
}

int main() {
    std::string s = "Bonjour le monde";
    std::string_view sv = s.substr(0, 7); // Crée une vue sur une sous-chaîne

    Afficher(sv); // Affiche "Bonjour"

    return 0;
}
