#include "SpellBook.hpp"

SpellBook::SpellBook()
{
}

SpellBook::~SpellBook()
{
    for (std::map<std::string, ASpell *>::iterator it = spellBook_.begin(); it != spellBook_.end(); ++it)
    {
        delete it->second;
    }
    spellBook_.clear();
}

void SpellBook::learnSpell(ASpell *spell)
{
    if (spell)
    {
        spellBook_[spell->getName()] = spell->clone();
    }
}

void SpellBook::forgetSpell(const std::string &spellName)
{
    std::map<std::string, ASpell *>::iterator it = spellBook_.find(spellName);
    if (it != spellBook_.end())
    {
        delete it->second;
        spellBook_.erase(it);
    }
}

ASpell *SpellBook::createSpell(const std::string &spellName)
{
    ASpell *tmp = NULL;
    if (spellBook_.find(spellName) != spellBook_.end())
    {
        tmp = spellBook_[spellName];
    }
    return (tmp);
}
