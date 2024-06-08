#pragma once

#include <iostream>
#include <stdexcept>

const int MAX_VAL = 100;
template <typename T> class Array
{
  private:
    T *_elements;
    unsigned int _size;

  public:
    Array();
    Array(unsigned int n);
    Array(Array const &src);
    Array &operator=(Array const &rhs);
    ~Array();

    T &operator[](unsigned int index);
    const T &operator[](unsigned int index) const;
    unsigned int size() const;

    void print() const;
};

#include "Array.tpp"
