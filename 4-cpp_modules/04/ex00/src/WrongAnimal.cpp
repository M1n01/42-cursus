/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:43:37 by minabe            #+#    #+#             */
/*   Updated: 2023/12/03 20:18:28 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("")
{
	std::cout << YELLOW << "WrongAnimal default constructor called." << DEFAULT << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
	std::cout << YELLOW << "WrongAnimal copy constructor called." << DEFAULT << std::endl;
	_type = src._type;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &rhs)
{
	std::cout << YELLOW << "WrongAnimal assignation operator called." << DEFAULT << std::endl;
	if (this != &rhs)
		_type = rhs._type;
	return (*this);
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << YELLOW << "WrongAnimal destructor called." << DEFAULT << std::endl;
}

std::string	WrongAnimal::getType(void) const
{
	return (_type);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << RED <<  "<Animal Sound>" << DEFAULT << std::endl;
}
