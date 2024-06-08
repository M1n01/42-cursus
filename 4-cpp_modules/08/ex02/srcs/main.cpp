#include "../includes/MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);
    std::cout << "Top element: " << mstack.top() << std::endl;

    mstack.pop();
    std::cout << "Stack size after pop: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << "\nStack contents (forward): ";
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Stack contents (reverse): ";
    for (MutantStack<int>::reverse_iterator it = mstack.rbegin(); it != mstack.rend(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    const MutantStack<int> mstackConst(mstack);
    std::cout << "Stack contents (const forward): ";
    for (MutantStack<int>::const_iterator it = mstackConst.begin(); it != mstackConst.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Stack contents (const reverse): ";
    for (MutantStack<int>::const_reverse_iterator it = mstackConst.rbegin(); it != mstackConst.rend(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::stack<int> s(mstack);

    for (std::stack<int> tmp = s; !tmp.empty(); tmp.pop())
    {
        std::cout << "Stack pop: " << tmp.top() << std::endl;
    }

    MutantStack<int> s2(mstack);
    MutantStack<int> s3;
    s3 = s2;

    std::cout << "Copy assigned stack contents: ";
    for (MutantStack<int>::iterator it = s3.begin(); it != s3.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "\nTesting with std::list:" << std::endl;
    std::list<int> lstack;
    lstack.push_back(5);
    lstack.push_back(17);
    std::cout << "List contents: ";
    for (std::list<int>::iterator it = lstack.begin(); it != lstack.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
