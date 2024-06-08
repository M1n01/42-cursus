#include "../includes/Span.hpp"

Span::Span() : capacity(0), numbers()
{
}

Span::Span(unsigned int n) : capacity(n), numbers()
{
}

Span::Span(Span const &other) : capacity(other.capacity), numbers(other.numbers)
{
}

Span &Span::operator=(Span const &other)
{
    if (this != &other)
    {
        capacity = other.capacity;
        numbers = other.numbers;
    }
    return *this;
}

Span::~Span()
{
}

void Span::addNumber(int n)
{
    if (numbers.size() < capacity)
        numbers.insert(n);
    else
        throw std::runtime_error("Container is full");
}

unsigned int Span::shortestSpan() const
{
    if (numbers.size() < 2)
        throw std::logic_error("Not enough numbers to calculate span");
    unsigned int min = UINT_MAX;
    std::multiset<int>::iterator it = numbers.begin();
    std::multiset<int>::iterator next = it;
    ++next;
    for (; next != numbers.end(); ++it, ++next)
    {
        const unsigned int diff = *next - *it;
        if (diff < min)
            min = diff;
    }
    return min;
}

unsigned int Span::longestSpan() const
{
    if (numbers.size() < 2)
        throw std::logic_error("Not enough numbers to calculate span");
    return *numbers.rbegin() - *numbers.begin();
}
