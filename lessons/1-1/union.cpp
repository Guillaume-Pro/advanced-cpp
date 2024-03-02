#include <iostream>

union MyUnion
{
    int intVal;
    float floatVal;
    char charVal;
};

int main()
{
    MyUnion testUnion = {42};

    // testUnion.intVal = 42;
    std::cout << "Valeur entière: " << testUnion.intVal << std::endl;
    std::cout << "Valeur flottante: " << testUnion.floatVal << std::endl;
    std::cout << "Valeur caractère: " << testUnion.charVal << std::endl;

    testUnion.floatVal = 3.14f;
    std::cout << "Valeur entière: " << testUnion.intVal << std::endl;
    std::cout << "Valeur flottante: " << testUnion.floatVal << std::endl;

    return 0;
}