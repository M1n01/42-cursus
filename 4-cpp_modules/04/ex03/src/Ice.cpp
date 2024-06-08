/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:12:57 by minabe            #+#    #+#             */
/*   Updated: 2023/12/03 17:14:13 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice & src) : AMateria(src._type) {}

Ice	&Ice::operator=(const Ice& rhs)
{
	if (this != &rhs)
		AMateria::operator=(rhs);
	return (*this);
}

Ice::~Ice() {}

AMateria*	Ice::clone() const
{
	try
	{
		return (new Ice(*this));
	}
	catch (const std::bad_alloc& e)
	{
		std::cerr << "Ice clone failed: " << e.what() << std::endl;
		return (NULL);
	}
}

void		Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
