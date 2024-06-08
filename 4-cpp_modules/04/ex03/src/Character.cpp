/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:18:53 by minabe            #+#    #+#             */
/*   Updated: 2023/12/03 21:33:17 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Character.hpp"

Character::Character(std::string const & name) : _name(name), _unequipCount(0)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	for (int i = 0; i < MAX_UMATERIAS; i++)
		_unequippedMaterias[i] = NULL;
}

Character::Character(const Character & src) : _name(src._name), _unequipCount(src._unequipCount)
{
	for (int i = 0; i < 4; i++)
	{
		if (src._inventory[i])
			_inventory[i] = src._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
	for (int i = 0; i < src._unequipCount; i++)
	{
		if (src._unequippedMaterias[i])
			_unequippedMaterias[i] = src._unequippedMaterias[i]->clone();
		else
			_unequippedMaterias[i] = NULL;
	}
}

Character	&Character::operator=(const Character& rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < 4; i++)
		{
			if (_inventory[i])
			{
				delete _inventory[i];
				_inventory[i] = NULL;
			}
			if (rhs._inventory[i])
				_inventory[i] = rhs._inventory[i]->clone();
		}
		for (int i = 0; i < MAX_UMATERIAS; i++)
		{
			if (_unequippedMaterias[i])
			{
				delete _unequippedMaterias[i];
				_unequippedMaterias[i] = NULL;
			}
			if (rhs._unequippedMaterias[i])
				_unequippedMaterias[i] = rhs._unequippedMaterias[i]->clone();
		}
		_name = rhs._name;
	}
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
	}
	for (int i = 0; i < _unequipCount; i++)
	{
		if (_unequippedMaterias[i])
			delete _unequippedMaterias[i];
	}
}

std::string const &	Character::getName() const
{
	return (_name);
}

void	Character::equip(AMateria* m)
{
	if (m == NULL)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			return ;
		}
	}
	std::cout << "Inventory is full." << std::endl;
}

void	Character::unequip(int idx)
{
	if (idx < 0 || 3 < idx || !_inventory[idx])
	{
		std::cerr << RED << "Error: invalid index" << DEFAULT << std::endl;
		return ;
	}
	_unequippedMaterias[_unequipCount] = _inventory[idx];
	_unequipCount++;
	_inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || 3 < idx || !_inventory[idx])
	{
		std::cerr << RED << "Error: invalid index" << DEFAULT << std::endl;
		return ;
	}
	_inventory[idx]->use(target);
}
