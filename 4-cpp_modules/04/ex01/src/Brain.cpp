/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:29:07 by minabe            #+#    #+#             */
/*   Updated: 2023/12/03 20:26:45 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << BLUE << "Brain default constructor called" << DEFAULT << std::endl;
	for (int i = 0; i < 100; i++)
		_ideas[i] = "nothing";
}

Brain::Brain(const Brain &src)
{
	std::cout << BLUE << "Brain copy constructor called" << DEFAULT << std::endl;
	for (int i = 0; i < 100; i++)
		_ideas[i] = src.getIdea(i);
}

Brain	&Brain::operator=(const Brain &rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < 100; i++)
			_ideas[i] = rhs.getIdea(i);
	}
	return (*this);
}

Brain::~Brain(void)
{
	std::cout << YELLOW << "Brain destructor called" << DEFAULT << std::endl;
}

std::string	Brain::getIdea(int index) const
{
	if (index < 0 || index > 99)
	{
		std::cerr << RED << "Index out of range" << DEFAULT << std::endl;
		return ("");
	}
	return (_ideas[index]);
}

void	Brain::setIdea(int index, const std::string &idea)
{
	if (index < 0 || index > 99)
	{
		std::cerr << RED << "Index out of range" << DEFAULT << std::endl;
		return ;
	}
	_ideas[index] = idea;
}
