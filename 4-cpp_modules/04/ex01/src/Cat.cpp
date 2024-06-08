/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 22:15:29 by minabe            #+#    #+#             */
/*   Updated: 2023/12/05 15:15:56 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
	std::cout << BLUE << "Cat default constructor called" << DEFAULT  << std::endl;
	_type = "Cat";
	try
	{
		_brain = new Brain();
	}
	catch (std::bad_alloc &e)
	{
		std::cerr << RED << "Memory allocation failed" << e.what() << DEFAULT << std::endl;
		std::exit(EXIT_FAILURE);
	}
}

Cat::Cat(const Cat &src) : Animal(src)
{
	std::cout << BLUE << "Cat copy constructor called" << DEFAULT << std::endl;
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

Cat	&Cat::operator=(const Cat &rhs)
{
	std::cout << BLUE << "Cat assignation operator called" << DEFAULT  << std::endl;
	if (this != &rhs)
	{
		Animal::operator=(rhs);
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

Cat::~Cat(void)
{
	std::cout << YELLOW << "Cat destructor called" << DEFAULT << std::endl;
	delete _brain;
}

void	Cat::makeSound(void) const
{
	std::cout << "(Cats don’t bark)" << std::endl;
}

Brain	*Cat::getBrain(void) const
{
	return (_brain);
}
