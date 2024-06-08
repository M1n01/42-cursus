/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:57:32 by minabe            #+#    #+#             */
/*   Updated: 2023/12/08 22:44:14 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "exception.hpp"

Intern::Intern(void)
{
	initializeFormCreators();
}

Intern::Intern(Intern const &src)
{
	*this = src;
	// initializeFormCreators();
}

Intern	&Intern::operator=(Intern const &rhs)
{
	if (this != &rhs)
		(void)rhs;
	return (*this);
}

Intern::~Intern(void) {}

const std::string	Intern::formNames[] = {"robotomy request", "shrubbery creation", "presidential pardon"};
Intern::FormCreator	Intern::formCreators[];

void	Intern::initializeFormCreators(void)
{
	formCreators[0] = RobotomyRequestForm::create;
	formCreators[1] = ShrubberyCreationForm::create;
	formCreators[2] = PresidentialPardonForm::create;
}

AForm	*Intern::makeForm(std::string const &formName, std::string const &target) const
{
	for (int i = 0; i < numForms; i++)
	{
		if (formName == formNames[i])
			return (formCreators[i](target));
	}
	throw FormNotFoundException();
}
