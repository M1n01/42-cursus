#include "../includes/Span.hpp"
#include <iostream>
#include <vector>

int main()
{
    try
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
        sp.addNumber(12);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    try
    {
        Span sp = Span(5);
        sp.addNumber(INT_MAX);
        sp.addNumber(INT_MIN);
        sp.addNumber(0);
        sp.addNumber(2);
        sp.addNumber(-5);
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    try
    {
        Span sp = Span(2);
        sp.addNumber(INT_MAX);
        sp.addNumber(INT_MIN);
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    try
    {
        Span sp(10000);
        std::vector<int> largeNumbers;
        for (int i = 1; i <= 10000; ++i)
        {
            largeNumbers.push_back(i);
        }
        sp.addNumbers(largeNumbers.begin(), largeNumbers.end());
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;

        Span sp2(sp);
        std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp2.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    try
    {
        Span sp(0);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    try
    {
        Span sp(5);
        std::cout << "Shortest span on empty Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span on empty Span: " << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
