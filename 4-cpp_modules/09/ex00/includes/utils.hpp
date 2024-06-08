#pragma once

#include "alias.hpp"
#include <iostream>
#include <sstream>

namespace utils
{
void printError(const std::string &message);
ParseValueResult parseValue(const std::string &valueStr);
ParseLineResult parseInputFileLine(const std::string &line);
bool validDate(const std::string &date);
} // namespace utils
