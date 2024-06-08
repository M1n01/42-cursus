#include "../includes/sort.hpp"

static PairVector createPairs(std::vector<int> &vec)
{
    PairVector pairs;
    for (size_t i = 0; i < vec.size(); i += 2)
    {
        // 大きい方をfirstにする
        std::pair<int, int> pair =
            (vec[i] > vec[i + 1]) ? std::make_pair(vec[i], vec[i + 1]) : std::make_pair(vec[i + 1], vec[i]);
        pairs.push_back(pair);
    }
    return pairs;
}

static std::vector<int> createChain(PairVector &pairs)
{
    std::vector<int> chain;
    for (PairVector::iterator it = pairs.begin(); it != pairs.end(); it++)
    {
        chain.push_back(it->first);
    }
    return chain;
}

void sortPairs(PairVector &pairs, const std::vector<int> &sortedChain)
{
    for (size_t i = 0; i < sortedChain.size(); i++)
    {
        const int findFirst = sortedChain[i];
        size_t j = i;
        while (findFirst != pairs[j].first)
            j++;
        std::swap(pairs[i], pairs[j]);
    }
}

static void insertElements(PairVector &pairs, const size_t size, const int unpairs)
{
    // 最初の要素は常に最小値
    pairs.insert(pairs.begin(), std::make_pair(pairs[0].second, NONE));
    pairs[1].second = NONE;

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
            PairVector::iterator beginIt = pairs.begin();
            PairVector::iterator insertIt = getInsertIt(unpairs, beginIt, beginIt + startIndex);
            pairs.insert(insertIt, std::make_pair(unpairs, NONE));
            startIndex++;
        }
        for (size_t j = startIndex; j != endIndex;)
        {
            PairVector::iterator beginIt = pairs.begin();
            const int insertValue = pairs[j].second;
#if DEBUG
            std::cout << "insertValue: " << insertValue << std::endl;
            std::cout << "Pairs: ";
            for (size_t k = 0; k < pairs.size(); k++)
            {
                std::cout << "(" << pairs[k].first << " " << pairs[k].second << ")" << " ";
            }
            std::cout << std::endl;
#endif

            if (insertValue == NONE)
            {
                --j;
                continue;
            }
            PairVector::iterator insertIt;

            insertIt = getInsertIt(insertValue, beginIt, beginIt + j);
            if (insertIt == pairs.end())
                throw std::logic_error("ERROR: logic getInsertIt");

            pairs[j].second = NONE;
            if (endIndex >= j)
            {
                endIndex++;
            }
            pairs.insert(insertIt, std::make_pair(insertValue, NONE));
#if DEBUG
            std::cout << "inserted Pairs: ";
            for (size_t k = 0; k < pairs.size(); k++)
            {
                std::cout << "(" << pairs[k].first << " " << pairs[k].second << ")" << " ";
            }
            std::cout << std::endl;
#endif
        }
    }
}

std::vector<int> mergeInsertionSort(std::vector<int> &vec)
{
    const size_t size = vec.size();
    if (vec.size() <= 1)
    {
        return vec;
    }
    int unpairs = NONE;
    if (size % 2 != 0)
    {
        unpairs = vec[size - 1];
        vec.pop_back();
    }

    // pairとchainを作成
    PairVector pairs = createPairs(vec);
    std::vector<int> chain = createChain(pairs);
#if DEBUG
    std::cout << "chain: ";
    for (size_t i = 0; i < chain.size(); i++)
    {
        std::cout << chain[i] << " ";
    }
    std::cout << std::endl;
#endif

    // chain sort
    std::vector<int> sortedChain = mergeInsertionSort(chain);
#if DEBUG
    std::cout << "sortedChain: ";
    for (size_t i = 0; i < sortedChain.size(); i++)
    {
        std::cout << sortedChain[i] << " ";
    }
    std::cout << std::endl;
#endif

    sortPairs(pairs, sortedChain); // ソートされたchainを元にpairをソート
#if DEBUG
    std::cout << "pairs: ";
    for (size_t i = 0; i < pairs.size(); i++)
    {
        std::cout << "(" << pairs[i].first << " " << pairs[i].second << ")" << " ";
    }
    std::cout << std::endl;
#endif

    insertElements(pairs, size, unpairs);
    // pairのfirstを返す
    std::vector<int> ret;
    for (PairVector::iterator it = pairs.begin(); it != pairs.end(); it++)
        ret.push_back((*it).first);

    return ret;
}
