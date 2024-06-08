/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:30:06 by minabe            #+#    #+#             */
/*   Updated: 2023/12/03 21:03:55 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		_materias[i] = NULL;
	_count = 0;
}

MateriaSource::MateriaSource(const MateriaSource& src)
{
	for (int i = 0; i < 4; i++)
		_materias[i] = src._materias[i]->clone();
	_count = src._count;
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < 4; i++)
		{
			if (_materias[i])
				delete _materias[i];
			_materias[i] = NULL;
		}
		_count = rhs._count;
		for (int i = 0; i < _count; i++)
			_materias[i] = rhs._materias[i]->clone();
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (_materias[i])
			delete _materias[i];
		_materias[i] = NULL;
	}
}

void	MateriaSource::learnMateria(AMateria* materia)
{
	if (materia == NULL)
		return ;
	for (int i = 0; i < _count; i++)
	{
		if (_materias[i] == materia)
			return ; // Already learned
	}
	if (_count < 4)
	{
		_materias[_count] = materia;
		_count++;
	}
	else
		std::cout << "MateriaSource is full." << std::endl;
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < _count; i++)
	{
		if (_materias[i]->getType() == type)
			return (_materias[i]->clone());
	}
	return (NULL);
}
