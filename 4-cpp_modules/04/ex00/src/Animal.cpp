/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 23:05:08 by minabe            #+#    #+#             */
/*   Updated: 2023/12/03 20:30:59 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Animal.hpp"

Animal::Animal(void) : _type("")
{
	std::cout << GREEN << "Animal default constructor called" << DEFAULT << std::endl;
}

Animal::Animal(const Animal &src)
{
	std::cout << GREEN << "Animal copy constructor called" << DEFAULT << std::endl;
	_type = src._type;
}

Animal	&Animal::operator=(const Animal &rhs)
{
	if (this != &rhs)
		_type = rhs._type;
	return (*this);
}

Animal::~Animal(void)
{
	std::cout << BLUE << "Animal destructor called" << DEFAULT << std::endl;
}

std::string	Animal::getType(void) const
{
	return (_type);
}

void	Animal::makeSound(void) const
{
	std::cout << RED << "<Animal Sound>" << DEFAULT << std::endl;
}
