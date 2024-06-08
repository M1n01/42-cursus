#pragma once

#include "Result.hpp"
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>

typedef Result<int, std::string> ConvertToIntResult;
typedef Result<float, std::string> ConvertToFloatResult;
typedef Result<double, std::string> ConvertToDoubleResult;
typedef Result<char, std::string> ConvertToCharResult;

class ScalarConverter
{
  private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &);
    ScalarConverter &operator=(const ScalarConverter &);
    ~ScalarConverter();

    static ConvertToCharResult convertToChar(const double &value);
    static ConvertToIntResult convertToInt(const double &value);
    static ConvertToFloatResult convertToFloat(const double &value);
    static ConvertToDoubleResult convertToDouble(const double &value);

  public:
    static void convert(const std::string &str);
};
