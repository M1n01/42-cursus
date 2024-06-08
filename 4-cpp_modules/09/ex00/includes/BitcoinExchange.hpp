#pragma once

#include "alias.hpp"
#include "utils.hpp"

#include <fstream>
#include <iostream>
#include <map>

class BitcoinExchange
{
  private:
    std::map<std::string, double> bitcoinPriceHistory;

    LoadDataBaseResult loadDataBase(void);

  public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    ~BitcoinExchange();

    double getPrice(const std::string &date) const;
};
