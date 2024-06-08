#pragma once

#include <algorithm>
#include <set>

class Span
{
  private:
    unsigned int capacity;
    std::multiset<int> numbers;

    Span();

  public:
    Span(unsigned int n);
    Span(Span const &other);
    Span &operator=(Span const &other);
    ~Span();

    void addNumber(int n);
    template <typename T> void addNumbers(T begin, T end)
    {
        if (static_cast<size_t>(std::distance(begin, end)) <= capacity - numbers.size())
            numbers.insert(begin, end);
        else
            throw std::runtime_error("Container is full");
    };
    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;
};
