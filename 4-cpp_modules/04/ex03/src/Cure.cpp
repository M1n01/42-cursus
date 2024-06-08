/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:09:17 by minabe            #+#    #+#             */
/*   Updated: 2023/12/03 17:14:24 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure & src) : AMateria(src._type) {}

Cure	&Cure::operator=(const Cure& rhs)
{
	if (this != &rhs)
		AMateria::operator=(rhs);
	return (*this);
}

Cure::~Cure() {}

AMateria*	Cure::clone() const
{
	try
	{
		return (new Cure(*this));
	}
	catch (const std::bad_alloc& e)
	{
		std::cerr << "Cure clone failed: " << e.what() << std::endl;
		return (NULL);
	}
}

void		Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
