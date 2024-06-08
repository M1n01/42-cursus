#include "../includes/RPN.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: ./rpn \"[RPN expression]\"" << std::endl;
        return 1;
    }
    rpn(argv[1]);
    return 0;
}
