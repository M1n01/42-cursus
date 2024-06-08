/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:05:34 by minabe            #+#    #+#             */
/*   Updated: 2023/12/02 12:21:35 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(nullptr) {}

HumanB::~HumanB(void) {}

void	HumanB::attack(void) const
{
	if (_weapon)
		std::cout << _name << " attacks with his " << _weapon->getType() << std::endl;
	else
		std::cout << RED << _name << " has no weapon to attack with." << DEFAULT << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}
