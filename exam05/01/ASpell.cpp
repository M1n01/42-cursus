#include "ASpell.hpp"

ASpell::ASpell(const std::string &name, const std::string &effects) : name_(name), effects_(effects)
{
}

ASpell &ASpell::operator=(const ASpell &rhs)
{
    if (this != &rhs)
    {
        this->name_ = rhs.name_;
        this->effects_ = rhs.effects_;
    }
    return (*this);
}

ASpell::~ASpell()
{
}

const std::string &ASpell::getName() const
{
    return (this->name_);
}

const std::string &ASpell::getEffects() const
{
    return (this->effects_);
}

void ASpell::launch(const ATarget &target) const
{
    target.getHitBySpell(*this);
}
