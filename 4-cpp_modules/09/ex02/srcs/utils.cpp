#include "../includes/utils.hpp"

void printVector(const std::vector<int> &vec)
{
    for (size_t i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

void printList(const std::list<int> &lst)
{
    for (std::list<int>::const_iterator it = lst.begin(); it != lst.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

unsigned int jacobsthal(unsigned int n)
{
    if (n == 0)
        return 0;
    return (pow(2, n + 1) + pow(-1, n)) / 3;
}

unsigned int jacobsthalIndex(unsigned int n)
{
    if (n == 0)
        return 0;
    return jacobsthal(n - 1) + jacobsthal(n) - 1;
}

std::vector<std::pair<int, int> >::iterator getInsertIt(int insert, std::vector<std::pair<int, int> >::iterator begin,
                                                        std::vector<std::pair<int, int> >::iterator end)
{
    const int middleIndex = (end - begin) / 2;
    if (middleIndex == 0)
    {
        if (insert <= (*begin).first)
        {
            return begin;
        }
        else if (insert <= (*end).first)
        {
            return end;
        }
        else
        {
            return end + 1;
        }
    }
    else
    {
        std::vector<std::pair<int, int> >::iterator middle = begin + middleIndex;
        if ((*middle).first > insert)
        {
            return getInsertIt(insert, begin, middle);
        }
        else
        {
            return getInsertIt(insert, middle, end);
        }
    }
}

std::list<std::pair<int, int> >::iterator getInsertIt(int insert, std::list<std::pair<int, int> >::iterator begin,
                                                      std::list<std::pair<int, int> >::iterator end)
{
    if (std::distance(begin, end) <= 1)
    {
        if (insert <= begin->first)
        {
            return begin;
        }
        else if (insert <= end->first)
        {
            return end;
        }
        else
        {
            return ++end;
        }
    }
    else
    {
        std::list<std::pair<int, int> >::iterator middle = begin;
        std::advance(middle, std::distance(begin, end) / 2);
        if (middle->first > insert)
        {
            return getInsertIt(insert, begin, middle);
        }
        else
        {
            return getInsertIt(insert, middle, end);
        }
    }
}
