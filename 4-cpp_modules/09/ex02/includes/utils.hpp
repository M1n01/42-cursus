#pragma once

#include <cmath>
#include <iostream>
#include <list>
#include <utility>
#include <vector>

void printVector(const std::vector<int> &vec);
void printList(const std::list<int> &lst);
unsigned int jacobsthal(unsigned int n);
unsigned int jacobsthalIndex(unsigned int n);
std::vector<std::pair<int, int> >::iterator getInsertIt(int insert, std::vector<std::pair<int, int> >::iterator begin,
                                                        std::vector<std::pair<int, int > >::iterator end);
std::list<std::pair<int, int> >::iterator getInsertIt(int insert, std::list<std::pair<int, int> >::iterator begin,
                                                      std::list<std::pair<int, int> >::iterator end);
