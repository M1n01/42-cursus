#pragma once

#include <algorithm>

template <typename T> typename T::iterator easyfind(T &container, int value);
template <typename T> typename T::const_iterator easyfind(const T &container, int value);

#include "easyfind.tpp"
