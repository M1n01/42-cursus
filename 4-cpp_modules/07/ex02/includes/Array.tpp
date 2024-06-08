#include "Array.hpp"

template <typename T> Array<T>::Array() : _elements(NULL), _size(0)
{
}

template <typename T> Array<T>::Array(unsigned int n) : _elements(new T[n]), _size(n)
{
}

template <typename T> Array<T>::Array(Array const &src) : _elements(new T[src._size]), _size(src._size)
{
    for (unsigned int i = 0; i < src._size; i++)
        _elements[i] = src._elements[i];
}

template <typename T> Array<T> &Array<T>::operator=(Array const &rhs)
{
    if (this != &rhs)
    {
        delete[] _elements;
        _elements = new T[rhs._size];
        _size = rhs._size;
        for (unsigned int i = 0; i < rhs._size; i++)
            _elements[i] = rhs._elements[i];
    }
    return *this;
}

template <typename T> Array<T>::~Array()
{
    delete[] _elements;
}

template <typename T> T &Array<T>::operator[](unsigned int i)
{
    if (i >= _size)
        throw std::out_of_range("Index out of bounds");
    return _elements[i];
}

template <typename T> T const &Array<T>::operator[](unsigned int i) const
{
    if (i >= _size)
        throw std::out_of_range("Index out of bounds");
    return _elements[i];
}

template <typename T> unsigned int Array<T>::size() const
{
    return _size;
}

template <typename T> void Array<T>::print() const
{
    for (unsigned int i = 0; i < _size; i++)
        std::cout << _elements[i] << std::endl;
}
