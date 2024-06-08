#pragma once

#include <cmath>
#include <deque>
#include <iostream>
#include <list>
#include <utility>
#include <vector>
#include <functional>

#include "utils.hpp"

#define DEBUG 0

const int NONE = -1;

typedef std::vector<std::pair<int, int> > PairVector;
typedef std::list<std::pair<int, int> > PairList;

std::vector<int> mergeInsertionSort(std::vector<int> &vec);
std::list<int> mergeInsertionSort(std::list<int> &list);
