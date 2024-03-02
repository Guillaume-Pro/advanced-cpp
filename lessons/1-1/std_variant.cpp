#include <iostream>
#include <variant>
#include <string>

// std::variant est un type de données qui permet de représenter une valeur parmi
// un ensemble de types possibles.
// https://en.cppreference.com/w/cpp/utility/variant

int main()
{
    std::variant<int, float, std::string> myVariant = {42};

    myVariant = 20; // Stocke un int
    std::cout << "Int: " << std::get<int>(myVariant) << std::endl;

    myVariant = 3.14f; // Stocke un float
    std::cout << "Float: " << std::get<float>(myVariant) << std::endl;

    myVariant = "Hello World"; // Stocke un std::string
    std::cout << "String: " << std::get<std::string>(myVariant) << std::endl;

    try
    {
        std::get<long>(myVariant);
    }
    catch (const std::bad_variant_access& exception)
    {
        std::cout << exception.what() << '\n';
    }

    return 0;
}


