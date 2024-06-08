#include "../includes/Array.hpp"

int main(void)
{
    Array<int> arr(5);

    std::cout << "====Normal array====" << std::endl;
    for (unsigned int i = 0; i < arr.size(); i++)
        arr[i] = i;
    arr.print();

    try
    {
        std::cout << "\n====Out of range====" << std::endl;
        arr[arr.size()] = 5;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n====Copy array====" << std::endl;
    Array<int> arr2(arr);
    for (unsigned int i = 0; i < arr2.size(); i++)
    {
        std::cout << arr2[i] << std::endl;
    }

    return 0;
}
