#pragma once

template <typename T> void iter(const T *array, const int length, void (*f)(T const &))
{
    for (int i = 0; i < length; i++)
        f(array[i]);
}
