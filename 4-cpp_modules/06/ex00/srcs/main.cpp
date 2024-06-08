#include "../includes/ScalarConverter.hpp"

static bool isprintChars(const std::string &str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if (!isprint(str[i]))
            return false;
    }
    return true;
}

int main(int argc, char *argv[])
{
    if (argc != 2 || !isprintChars(argv[1]))
    {
        std::cout << "Usage: ./convert [print chars]" << std::endl;
        return 1;
    }
    ScalarConverter::convert(argv[1]); // 先に肩を突き止める
    return 0;
}
