#include "Warlock.hpp"

Warlock::Warlock(std::string name, std::string title) : name_(name), title_(title)
{
    std::cout << name_ << ": This looks like another boring day." << std::endl;
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

void Warlock::learnSpell(ASpell *spell)
{
    if (spell)
    {
        spellBook_[spell->getName()] = spell;
    }
}

void Warlock::forgetSpell(const std::string &spellName)
{
    if (spellBook_.find(spellName) != spellBook_.end())
    {
        delete spellBook_[spellName];
        spellBook_.erase(spellName);
    }
}

void Warlock::launchSpell(const std::string &spellName, ATarget const &target)
{
    if (spellBook_.find(spellName) != spellBook_.end())
    {
        spellBook_[spellName]->launch(target);
    }
}
