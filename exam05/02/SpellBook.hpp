#pragma once

#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"

class SpellBook
{
private:
    std::map<std::string, ASpell *> spellBook_;

    SpellBook(const SpellBook &other);
    SpellBook &operator=(const SpellBook &other);

public:
    SpellBook();
    ~SpellBook();

    void learnSpell(ASpell *spell);
    void forgetSpell(const std::string &spellName);
    ASpell *createSpell(const std::string &spellName);
};
