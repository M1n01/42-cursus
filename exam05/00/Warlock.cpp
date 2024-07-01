#include "Warlock.hpp"

Warlock::Warlock(std::string name, std::string title) : name_(name), title_(title)
{
    std::cout << name_ << ": This looks like another boring day." << std::endl;
}

Warlock::Warlock()
{
}

Warlock &Warlock::operator=(Warlock const &rhs)
{
    name_ = rhs.name_;
    title_ = rhs.title_;
    return *this;
}

Warlock::Warlock(Warlock const &obj)
{
    *this = obj;
}

Warlock::~Warlock()
{
    std::cout << name_ << ": My job here is done!" << std::endl;
}

std::string const &Warlock::getName() const
{
    return (name_);
}

std::string const &Warlock::getTitle() const
{
    return (title_);
}

void Warlock::setTitle(std::string const &str)
{
    title_ = str;
}

void Warlock::introduce() const
{
    std::cout << name_ << ": I am " << name_ << ", " << title_ << "!" << std::endl;
}
