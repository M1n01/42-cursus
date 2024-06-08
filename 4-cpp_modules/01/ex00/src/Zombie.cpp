/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 21:01:13 by minabe            #+#    #+#             */
/*   Updated: 2023/11/11 17:54:18 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void): _name("") {}

Zombie::Zombie(std::string name): _name(name) {}

Zombie::~Zombie(void)
{
	std::cout << RED << _name << " is destroyed for debugging." << DEFAULT << std::endl;
}

void	Zombie::announce(void)
{
	std::cout  << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
