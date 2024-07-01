#pragma once

#include <iostream>

class Warlock
{
private:
    Warlock &operator=(Warlock const &rhs);
    Warlock(Warlock const &obj);
    Warlock();
    std::string name_;
    std::string title_;

public:
    Warlock(std::string name, std::string title);
    ~Warlock();
    std::string const &getName() const;
    std::string const &getTitle() const;
    void setTitle(std::string const &str);
    void introduce() const;
};
