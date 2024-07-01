#include "ATarget.hpp"

ATarget::ATarget(const std::string &type)
{
    this->type_ = type;
}

ATarget::~ATarget()
{
}

const std::string &ATarget::getType() const
{
    return (this->type_);
}

void ATarget::getHitBySpell(const ASpell &spell) const
{
    std::cout << this->type_ << " has been " << spell.getEffects() << "!" << std::endl;
}
