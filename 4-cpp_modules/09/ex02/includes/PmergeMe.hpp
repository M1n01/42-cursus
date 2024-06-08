#pragma once

#include "sort.hpp"

class PMergeMe
{
  private:
    std::vector<int> inputVector;
    std::list<int> inputList;
    std::vector<int> outputVector;

    PMergeMe();
    PMergeMe(const PMergeMe &other);
    PMergeMe &operator=(const PMergeMe &other);

  public:
    PMergeMe(const std::vector<int> &inputVector, const std::list<int> &inputList);
    ~PMergeMe();

    void ex02();
};
