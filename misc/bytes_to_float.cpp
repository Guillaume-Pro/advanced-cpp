#include <iostream>
#include <filesystem>


int main() {
    uint8_t integerBytes[] = {0x13,0x00,0x00,0x00}; // 19,5°C
    uint8_t decimalBytes[] = {0xC3,0x50,0x00,0x00}; // 19,5°C

    int val1 = *reinterpret_cast<int*>(integerBytes);
    int val2 = *reinterpret_cast<int*>(decimalBytes);

    int intPart = 0x13 << 0x00 << 0x00 << 0x00;
    int decPart = 0xC3 << 0x50 << 0x00 << 0x00;

    float value = val1 + val2 * 10^(-6);
    float valuePart = intPart + decPart * 10^(-6);

    std::cout << val1 << std::endl;
    std::cout << val2 << std::endl;
    std::cout << "value " << value << std::endl;
    std::cout << "intPart: " << intPart << " decPart: " << decPart << " valuePart: " << valuePart << std::endl;
    std::cout << 0xC3 << " " << 0x50 << " " << 0x00 << " " << 0x00 << std::endl;

    return 0;
}
