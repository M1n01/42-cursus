/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:52:26 by minabe            #+#    #+#             */
/*   Updated: 2023/12/03 20:43:52 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : _type(type) {}

AMateria::AMateria(AMateria const & src)
{
	_type = src._type;
}

AMateria	&AMateria::operator=(AMateria const & rhs)
{
	if (this != &rhs)
		_type = rhs._type;
	return (*this);
}

AMateria::~AMateria() {}

std::string const &	AMateria::getType() const
{
	return (this->_type);
}

void	AMateria::use(ICharacter& target)
{
	(void)target;
}
