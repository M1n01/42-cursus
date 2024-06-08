#include "../includes/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    std::cout << "Loading database..." << std::endl;
    LoadDataBaseResult result = this->loadDataBase();
    if (!result.success)
    {
        throw std::logic_error(result.error);
    }
    std::cout << "Database loaded!\n" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    this->bitcoinPriceHistory = other.bitcoinPriceHistory;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    this->bitcoinPriceHistory = other.bitcoinPriceHistory;
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

LoadDataBaseResult BitcoinExchange::loadDataBase(void)
{
    std::ifstream file(DATABASE_PATH);
    if (file.is_open())
    {
        std::string line;
        std::getline(file, line); // skip header
        if (line != "date,exchange_rate")
        {
            return LoadDataBaseResult::Error("bad header");
        }
        while (std::getline(file, line))
        {
            const std::string date = line.substr(0, line.find(","));
            if (utils::validDate(date))
            {
                const std::string price = line.substr(line.find(",") + 1);
                ParseValueResult result = utils::parseValue(price);
                if (result.success)
                {
                    this->bitcoinPriceHistory[date] = result.value;
                }
                else
                {
                    return LoadDataBaseResult::Error(result.error);
                }
            }
            else
            {
                return LoadDataBaseResult::Error("bad input => " + date);
            }
        }
        file.close();
        return LoadDataBaseResult::Success(SUCCESS);
    }
    else
    {
        return LoadDataBaseResult::Error("could not open file.");
    }
}

double BitcoinExchange::getPrice(const std::string &date) const
{
    std::map<std::string, double>::const_iterator it = this->bitcoinPriceHistory.begin();
    double prevPrice = it->second;
    while (it != this->bitcoinPriceHistory.end())
    {
        if (it->first == date)
        {
            return it->second;
        }
        else if (it->first > date)
        {
            break;
        }
        prevPrice = it->second;
        it++;
    }
    return prevPrice;
}
