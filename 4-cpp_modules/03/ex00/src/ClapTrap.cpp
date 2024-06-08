/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 18:22:16 by minabe            #+#    #+#             */
/*   Updated: 2023/12/02 23:25:37 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("ClapTrap"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap default constructor called." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap constructor called." << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor called." << std::endl;
}

void	ClapTrap::printStatus(void) const
{
	std::cout << "====" <<  this->_name << "のステータス====" << std::endl;
	std::cout << "[HP]: " << this->_hitPoints << "/" << 10 << std::endl;
	std::cout << "[EP]: " << this->_energyPoints << std::endl;
	std::cout << "[ATK]: " << this->_attackDamage << std::endl << std::endl;
}

bool	ClapTrap::isAlive(void) const
{
	if (this->_hitPoints < 1)
	{
		std::cout << "『" << this->_name << "は瀕死状態だ。』" << std::endl;
		return (false);
	}
	return (true);
}

bool	ClapTrap::canAction(void) const
{
	if (this->_energyPoints < 1)
	{
		std::cout << "『" << this->_name << "はEPが足りない。』" << std::endl;
		return (false);
	}
	return (true);
}

void	ClapTrap::attack(const std::string& target)
{
	if (!this->isAlive() || !this->canAction())
		std::cout << "『" << this->_name << "は攻撃できなかった。』" << std::endl;
	else
	{
		std::cout << "『" << this->_name << "は、たいあたりを繰り出した！" << target << "は" << this->_attackDamage << "のダメージ!!" << "』" << std::endl;
		this->_energyPoints--;
	}
	printStatus();
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (!this->isAlive())
	{
		std::cout << "『目の前が真っ暗になった。』" << std::endl;
		return ;
	}
	std::cout << "『" << this->_name << "は、たいあたりをくらった。" << amount << "のダメージ!!" << "』" << std::endl;
	if (this->_hitPoints <= amount)
	{
		std::cout << "『" << this->_name << "は力尽きた。』" << std::endl;
		this->_hitPoints = 0;
	}
	else
		this->_hitPoints -= amount;
	printStatus();
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->isAlive() || !this->canAction())
		std::cout << "『傷薬を使えなかった。』" << std::endl;
	else if (this->_hitPoints == 10)
		std::cout << "『傷薬を使えなかった。" << this->_name << "のHPはすでに満タンだ。』" << std::endl;
	else if (this->_hitPoints + amount > 10)
	{
		std::cout << "『" << this->_name << "は、傷薬を使った。HPが満タンになった。』" << std::endl;
		this->_hitPoints = 10;
		this->_energyPoints--;
	}
	else
	{
		std::cout << "『" << this->_name << "は、傷薬を使った。" << amount << "回復した。" << "』" << std::endl;
		this->_hitPoints += amount;
		this->_energyPoints--;
	}
	printStatus();
}
