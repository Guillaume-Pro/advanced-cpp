#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

int main() {
    fs::path path = "/home/john_doe";

    std::cout << "Files in " << path << ":\n";
    for (const auto& entry : fs::directory_iterator(path)) {
        std::cout << entry.path() << std::endl; // Affiche le chemin de chaque fichier
    }

    return 0;
}
