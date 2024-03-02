#include <iostream>
#include <optional>

// std::optional est un type de données qui permet de représenter une valeur optionnelle.
// https://en.cppreference.com/w/cpp/utility/optional

std::optional<int> divide(const int&& numerator, const int&& denominator)
{
    if (denominator == 0)
        return std::nullopt; // Returns an empty optional

    return numerator / denominator; // Returns the result encapsulated in an optional
}

int main()
{
    const auto validResult = divide(10, 2);
    std::cout << "Result: " << validResult.value() << std::endl; // Console: Result: 5

    const auto dividedByZero = divide(10, 0);

    // std::cout << "Division valide: " << dividedByZero.value() << std::endl; // Throws bad_optional_access
    std::cout << "Result: " << dividedByZero.value_or(0) << std::endl; // Console: Result: 0

    if (!dividedByZero)
        std::cout << "if (!dividedByZero) => " << "Error: Divided by zero." << std::endl;

    if (!dividedByZero.has_value())
        std::cout << "if (!dividedByZero.has_value()) => " << "Error: Divided by zero." << std::endl;

    return 0;
}
