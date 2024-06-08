#include "../includes/utils.hpp"

static int calculateMaxDays(const int &year, const int &month)
{
    int maxDays;
    if (month == 2)
    {
        // 2月の場合、うるう年かどうかで最大日数が変わる
        const bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        maxDays = isLeapYear ? 29 : 28;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
        maxDays = 30;
    else
        maxDays = 31;

    return maxDays;
}

static std::pair<std::string, std::string> splitLine(const std::string &line)
{
    std::istringstream iss(line);
    std::string date;
    std::string valueStr;

    if (!std::getline(iss, date, '|'))
        date = line;

    std::getline(iss, valueStr);

    return std::make_pair(date, valueStr);
}

namespace utils
{
void printError(const std::string &message)
{
    std::cerr << "Error: " << message << std::endl;
}

ParseValueResult parseValue(const std::string &valueStr)
{
    if (!valueStr.empty())
    {
        char *endptr;
        const double value = std::strtod(valueStr.c_str(), &endptr);
        if (endptr == valueStr.c_str() + valueStr.length())
        {
            if (value >= 0 && value <= std::numeric_limits<int>::max())
                return ParseValueResult::Success(value);
            else if (value < 0)
                return ParseValueResult::Error("not a positive number => " + valueStr);
            else
                return ParseValueResult::Error("too large a number => " + valueStr);
        }
        else
            return ParseValueResult::Error("invalid value format => " + valueStr + " (not a number)");
    }
    else
        return ParseValueResult::Error("a value is required");
}

ParseLineResult parseInputFileLine(const std::string &line)
{
    if (!line.empty())
    {
        const std::pair<std::string, std::string> tokens = splitLine(line);
        const std::string &date = tokens.first;
        const std::string &valueStr = tokens.second;

        if (utils::validDate(date))
        {
            const ParseValueResult valueResult = utils::parseValue(valueStr);
            if (valueResult.success)
                return ParseLineResult::Success(std::make_pair(date, valueResult.value));
            else
                return ParseLineResult::Error(valueResult.error);
        }
        else
            return ParseLineResult::Error("bad input => " + date);
    }
    else
        return ParseLineResult::Error("empty line");
}

bool validDate(const std::string &date)
{
    int year, month, day;
    char dash;

    std::istringstream iss(date);
    if (!(iss >> year >> dash >> month >> dash >> day))
    {
        return false;
    }

    if (month < 1 || month > 12)
    {
        return false;
    }

    // 日の範囲をチェック
    const int maxDays = calculateMaxDays(year, month);
    if (day < 1 || day > maxDays)
        return false;

    if (year < 2009 || (year == 2009 && month == 1 && day < 2)) // 2009年1月2日以降のデータのみ有効
        return false;

    return true;
}
} // namespace utils
