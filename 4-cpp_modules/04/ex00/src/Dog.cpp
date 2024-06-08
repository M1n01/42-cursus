/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 22:15:38 by minabe            #+#    #+#             */
/*   Updated: 2023/12/03 20:29:20 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	std::cout << BLUE << "Dog default constructor called" << DEFAULT << std::endl;
	_type = "Dog";
}

Dog::Dog(const Dog &src) : Animal(src)
{
	std::cout << BLUE << "Dog copy constructor called" << DEFAULT << std::endl;
}

Dog	&Dog::operator=(const Dog &rhs)
{
	std::cout << BLUE << "Dog assignation operator called" << std::endl;
	if (this != &rhs)
		Animal::operator=(rhs);
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << YELLOW << "Dog destructor called" << DEFAULT << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << "Bowwow!!" << std::endl;
}
