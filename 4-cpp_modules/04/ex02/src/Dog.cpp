/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 22:15:38 by minabe            #+#    #+#             */
/*   Updated: 2023/12/05 15:26:26 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : AAnimal()
{
	std::cout << BLUE << "Dog default constructor called" << DEFAULT << std::endl;
	_type = "Dog";
	_brain = new Brain();
}

Dog::Dog(const Dog &src) : AAnimal(src)
{
	std::cout << BLUE << "Dog copy constructor called" << std::endl;
	try
	{
		_brain = new Brain(*src._brain);
	}
	catch (std::bad_alloc &e)
	{
		std::cerr << RED << "Memory allocation failed" << e.what() << DEFAULT << std::endl;
		std::exit(EXIT_FAILURE);
	}
	_type = src._type;
	for (int i = 0; i < 100; i++)
		_brain->setIdea(i, src._brain->getIdea(i));
}

Dog	&Dog::operator=(const Dog &rhs)
{
	std::cout << BLUE << "Dog assignation operator called" << std::endl;
	if (this != &rhs)
	{
		AAnimal::operator=(rhs);
		delete _brain;
		try
		{
			_brain = new Brain(*rhs._brain);
		}
		catch (std::bad_alloc &e)
		{
			std::cerr << RED << "Memory allocation failed" << e.what() << DEFAULT << std::endl;
			std::exit(EXIT_FAILURE);
		}
	}
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << YELLOW << "Dog destructor called" << DEFAULT << std::endl;
	delete _brain;
}

void	Dog::makeSound(void) const
{
	std::cout << "Bowwow!!" << std::endl;
}

Brain	*Dog::getBrain(void) const
{
	return (_brain);
}
