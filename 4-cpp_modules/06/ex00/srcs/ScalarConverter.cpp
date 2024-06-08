#include "ScalarConverter.hpp"


bool is_nan(const double value)
{
    return value != value;
}

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &) {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &)
{
    return *this;
}

ScalarConverter::~ScalarConverter() {}

ConvertToCharResult ScalarConverter::convertToChar(const double &value)
{
    if (value < 0 || value > 127 || is_nan(value))
        return ConvertToCharResult::Error("impossible");
    if (std::isprint(static_cast<char>(value)))
        return ConvertToCharResult::Success(static_cast<char>(value));
    return ConvertToCharResult::Error("Non displayable");
}

ConvertToIntResult ScalarConverter::convertToInt(const double &value)
{
    if (value < INT_MIN || value > INT_MAX || is_nan(value))
        return ConvertToIntResult::Error("impossible");
    return ConvertToIntResult::Success(static_cast<int>(value));
}

ConvertToFloatResult ScalarConverter::convertToFloat(const double &value)
{
    if (value < std::numeric_limits<float>::min() || value > std::numeric_limits<float>::max())
        return ConvertToFloatResult::Error("impossible");
    return ConvertToFloatResult::Success(static_cast<float>(value)); // 2**127がマックス？
}

ConvertToDoubleResult ScalarConverter::convertToDouble(const double &value)
{
    return ConvertToDoubleResult::Success(value);
}

void ScalarConverter::convert(const std::string &str)
{
    static double value = strtod(str.c_str(), NULL);

    std::cout << "char: ";
    const ConvertToCharResult charResult = convertToChar(value);
    if (charResult.success)
        std::cout << "'" << charResult.value << "'" << std::endl;
    else
        std::cout << charResult.error << std::endl;

    std::cout << "int: ";
    const ConvertToIntResult intResult = convertToInt(value);
    if (intResult.success)
        std::cout << intResult.value << std::endl;
    else
        std::cout << intResult.error << std::endl;

    std::cout << "float: ";
    const ConvertToFloatResult floatResult = convertToFloat(value);
    if (floatResult.success)
        std::cout << std::fixed << std::setprecision(1) << floatResult.value << "f" << std::endl;
    else
        std::cout << floatResult.error << std::endl;

    std::cout << "double: ";
    const ConvertToDoubleResult doubleResult = convertToDouble(value);
    if (doubleResult.success)
        std::cout << std::fixed << std::setprecision(1) << doubleResult.value << std::endl;
    else
        std::cout << doubleResult.error << std::endl;
}
