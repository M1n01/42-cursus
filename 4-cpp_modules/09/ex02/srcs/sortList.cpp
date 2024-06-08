#include "../includes/sort.hpp"

static PairList createPairs(std::list<int> &lst)
{
    PairList pairs;
    std::list<int>::iterator it = lst.begin();
    while (it != lst.end())
    {
        std::list<int>::iterator next = it;
        ++next;
        if (next != lst.end())
        {
            // 大きい方をfirstにする
            std::pair<int, int> pair = (*it > *next) ? std::make_pair(*it, *next) : std::make_pair(*next, *it);
            pairs.push_back(pair);
            ++it;
        }
        ++it;
    }
    return pairs;
}

static std::list<int> createChain(PairList &pairs)
{
    std::list<int> chain;
    for (PairList::iterator it = pairs.begin(); it != pairs.end(); ++it)
    {
        chain.push_back(it->first);
    }
    return chain;
}

void sortPairs(PairList &pairs, const std::list<int> &sortedChain)
{
    size_t loopCount = 0;
    for (std::list<int>::const_iterator chainIt = sortedChain.begin(); chainIt != sortedChain.end();
         ++chainIt, ++loopCount)
    {
        const int findFirst = *chainIt;

        PairList::iterator it = pairs.begin();
        std::advance(it, loopCount);

        PairList::iterator findIt = it;
        while (findFirst != findIt->first)
        {
            ++findIt;
        }
        std::swap(*it, *findIt);
    }
}

static void insertElements(PairList &pairs, const size_t size, const int unpairs)
{
    // 最初の要素は常に最小値
    pairs.insert(pairs.begin(), std::make_pair(pairs.front().second, NONE));
    ++(++pairs.begin())->second = NONE;

#if DEBUG
    std::cout << "\n[Insertion sort]" << std::endl;
#endif
    for (size_t i = 2; pairs.size() < size; i++)
    {
        size_t startIndex = (jacobsthalIndex(i) >= pairs.size()) ? pairs.size() - 1 : jacobsthalIndex(i);
        size_t endIndex = jacobsthalIndex(i - 1);
#if DEBUG
        std::cout << "startIndex: " << startIndex << std::endl;
        std::cout << "endIndex: " << endIndex << std::endl;
#endif

        if (endIndex >= pairs.size())
            throw std::logic_error("endIndex (jacobstal)");

        if (startIndex == pairs.size() - 1 && unpairs != NONE)
        {
            PairList::iterator beginIt = pairs.begin();
            PairList::iterator endIter = pairs.begin();
            std::advance(endIter, startIndex);
            PairList::iterator insertItr = getInsertIt(unpairs, beginIt, endIter);
            pairs.insert(insertItr, std::make_pair(unpairs, NONE));
            startIndex++;
        }
        PairList::iterator j = pairs.begin();
        std::advance(j, startIndex);
        while (j != pairs.begin())
        {
            PairList::iterator beginIt = pairs.begin();
            const int insertValue = j->second;
#if DEBUG
            std::cout << "insertValue: " << insertValue << std::endl;
            std::cout << "Pairs: ";
            for (PairList::iterator k = pairs.begin(); k != pairs.end(); ++k)
            {
                std::cout << "(" << k->first << " " << k->second << ")" << " ";
            }
            std::cout << std::endl;
#endif

            if (insertValue == NONE)
            {
                --j;
                continue;
            }
            PairList::iterator insertItr;

            insertItr = getInsertIt(insertValue, beginIt, j);
            if (insertItr == pairs.end())
                throw std::logic_error("ERROR: logic getInsertIt");

            j->second = NONE;
            if (std::distance(pairs.begin(), j) <= static_cast<int>(endIndex))
            {
                endIndex++;
            }
            pairs.insert(insertItr, std::make_pair(insertValue, NONE));
#if DEBUG
            std::cout << "inserted Pairs: ";
            for (PairList::iterator k = pairs.begin(); k != pairs.end(); ++k)
            {
                std::cout << "(" << k->first << " " << k->second << ")" << " ";
            }
            std::cout << std::endl;
#endif
            std::advance(j, -1);
        }
    }
}

std::list<int> mergeInsertionSort(std::list<int> &lst)
{
    const size_t size = lst.size();
    if (lst.size() <= 1)
    {
        return lst;
    }
    int unpairs = NONE;
    if (size % 2 != 0)
    {
        unpairs = lst.back();
        lst.pop_back();
    }

    // pairとchainを作成
    PairList pairs = createPairs(lst);
    std::list<int> chain = createChain(pairs);
#if DEBUG
    std::cout << "chain: ";
    for (std::list<int>::iterator it = chain.begin(); it != chain.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
#endif

    // chain sort
    std::list<int> sortedChain = mergeInsertionSort(chain);
#if DEBUG
    std::cout << "sortedChain: ";
    for (std::list<int>::iterator it = sortedChain.begin(); it != sortedChain.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
#endif

    sortPairs(pairs, sortedChain); // ソートされたchainを元にpairをソート
#if DEBUG
    std::cout << "pairs: ";
    for (PairList::iterator itr = pairs.begin(); itr != pairs.end(); ++itr)
    {
        std::cout << "(" << itr->first << " " << itr->second << ")" << " ";
    }
    std::cout << std::endl;
#endif

    insertElements(pairs, size, unpairs);
    // pairのfirstを返す
    std::list<int> ret;
    for (PairList::iterator itr = pairs.begin(); itr != pairs.end(); ++itr)
        ret.push_back(itr->first);

    return ret;
}
