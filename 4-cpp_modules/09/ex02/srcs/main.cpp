#include "../includes/PmergeMe.hpp"
#include <ctime>
#include <iostream>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << "Error: Incorrect number of arguments. Usage: ./PmergeMe <positive_integers>" << std::endl;
        return 1;
    }
    else
    {
        std::vector<int> inputVector;
        std::list<int> inputList;

        for (int i = 1; argv[i]; i++)
        {
            char *endptr;
            const long num = std::strtol(argv[i], &endptr, 10);

            if (*endptr != '\0' || num <= 0 || num > std::numeric_limits<int>::max())
            {
                std::cout << "Error: Invalid input. Please provide positive integers only." << std::endl;
                return 1;
            }
            inputVector.push_back(static_cast<int>(num));
            inputList.push_back(static_cast<int>(num));
        }

        PMergeMe pmergeMe(inputVector, inputList);
        pmergeMe.ex02();
    }
    return 0;
}
