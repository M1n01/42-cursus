#include "../includes/BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        utils::printError("could not open file.");
        return 1;
    }
    else if (argc > 2)
    {
        utils::printError("Too many args.");
        return 1;
    }
    else
    {
        try
        {
            BitcoinExchange exchange;
            std::ifstream file(argv[1]);
            std::string line;

            if (file.is_open())
            {
                std::getline(file, line); // 1行目は見出し
                if (line != "date | value")
                {
                    utils::printError("invalid file format.");
                    return 1;
                }
                while (std::getline(file, line))
                {
                    const ParseLineResult result = utils::parseInputFileLine(line);
                    if (result.success)
                    {
                        const std::string &date = result.value.first;
                        const double &value = result.value.second;
                        std::cout << date << " => " << value << " = " << value * exchange.getPrice(date) << std::endl;
                    }
                    else
                    {
                        utils::printError(result.error);
                    }
                }
            }
            else
            {
                utils::printError("could not open file.");
            }
        }
        catch (std::exception &e)
        {
            utils::printError(e.what());
            return 1;
        }

        return 0;
    }
}
