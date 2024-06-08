#include "../includes/easyfind.hpp"
#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

int main()
{
    std::vector<int> vec;
    const int arrVec[] = {1, 2, 3, 4, 5, 'a'};
    vec.insert(vec.end(), arrVec, arrVec + sizeof(arrVec) / sizeof(arrVec[0]));
    std::vector<int>::iterator vecIt = easyfind(vec, 3);
    std::cout << "Found in vector: " << *vecIt << std::endl;

    const std::vector<int> constVec(arrVec, arrVec + sizeof(arrVec) / sizeof(arrVec[0]));
    std::vector<int>::const_iterator constVecIt = easyfind(vec, 3);
    std::cout << "Found in const vector: " << *constVecIt << std::endl;

    std::list<int> lst;
    const int arr[] = {6, 7, 8, 9, 10};
    lst.insert(lst.end(), arr, arr + sizeof(arr) / sizeof(arr[0]));
    std::list<int>::iterator listIt = easyfind(lst, 9);
    std::cout << "Found in list: " << *listIt << std::endl;

    // 以下の行は例外を投げる
    try
    {
        std::vector<int>::iterator vecItNotFound = easyfind(vec, 10);
        std::cout << "Found in vector: " << *vecItNotFound << std::endl;
    }
    catch (std::runtime_error &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
