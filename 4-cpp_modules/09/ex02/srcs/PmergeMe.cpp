#include "../includes/PmergeMe.hpp"
#include <fstream>

PMergeMe::PMergeMe(const std::vector<int> &inputVector, const std::list<int> &inputList)
    : inputVector(inputVector), inputList(inputList)
{
}

PMergeMe::~PMergeMe()
{
}


void PMergeMe::ex02()
{
    std::vector<int> vector(inputVector);
    std::list<int> list(inputList);

    std::cout << "Before: ";
    // printVector(vector);
    printList(list);

    std::clock_t start = std::clock();
    const std::vector<int> retVec = mergeInsertionSort(vector);
    std::clock_t end = std::clock();

    std::clock_t start2 = std::clock();
    const std::list<int> retList = mergeInsertionSort(list);
    std::clock_t end2 = std::clock();

    std::cout << "After: ";
    // printVector(retVec);
    printList(retList);

    const double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
    std::cout << "Time to process a range of " << vector.size() << " elements with std::vector : " << duration << " us"
              << std::endl;

    const double duration2 = static_cast<double>(end2 - start2) / CLOCKS_PER_SEC * 1000000;
    std::cout << "Time to process a range of " << list.size() << " elements with std::list : " << duration2 << " us"
              << std::endl;

    // retVecをテキストファイルに出力
    std::ofstream vecFile("retVec.txt");
    for (std::vector<int>::const_iterator it = retVec.begin(); it != retVec.end(); ++it)
        vecFile << *it << " ";
    vecFile.close();

    // retListをテキストファイルに出力
    std::ofstream listFile("retList.txt");
    for (std::list<int>::const_iterator it = retList.begin(); it != retList.end(); ++it)
        listFile << *it << " ";
    listFile.close();

    return;
}
