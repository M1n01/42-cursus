#include "iter.hpp"
#include <iostream>

template <typename T> void print(const T &element)
{
    std::cout << element << " ";
}

int main(void)
{
    const int intArray[] = {1, 2, 3, 4, 5};
    const float floatArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    const std::string stringArray[] = {"one", "two", "three", "four", "five"};

    std::cout << "intArray: ";
    iter<int>(intArray, sizeof(intArray) / sizeof(intArray[0]), print);
    std::cout << std::endl;

    std::cout << "floatArray: ";
    iter<float>(floatArray, sizeof(floatArray) / sizeof(floatArray[0]), print);
    std::cout << std::endl;

    std::cout << "stringArray: ";
    iter<std::string>(stringArray, sizeof(stringArray) / sizeof(stringArray[0]), print);
    std::cout << std::endl;

    return 0;
}
