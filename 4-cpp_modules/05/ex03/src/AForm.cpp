/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:36:33 by minabe            #+#    #+#             */
/*   Updated: 2023/12/07 17:54:45 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void) : _name("Default"), _signed(false), _gradeToSign(HIGHEST_GRADE), _gradeToExecute(HIGHEST_GRADE) {}

AForm::AForm(std::string const &name, unsigned int gradeToSign, int gradeToExecute)
	: _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < HIGHEST_GRADE || gradeToExecute < HIGHEST_GRADE)
		throw GradeTooHighException();
	else if (gradeToSign > LOWEST_GRADE || gradeToExecute > LOWEST_GRADE)
		throw GradeTooLowException();
}

AForm::AForm(AForm const &src)
	: _name(src._name), _signed(src._signed), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute) {}

AForm	&AForm::operator=(AForm const &rhs)
{
	if (this != &rhs)
		_signed = rhs._signed;
	return (*this);
}

AForm::~AForm(void) {}

const std::string	&AForm::getName(void) const
{
	return (_name);
}

bool	AForm::getSigned(void) const
{
	return (_signed);
}

unsigned int	AForm::getGradeToSign(void) const
{
	return (_gradeToSign);
}

unsigned int	AForm::getGradeToExecute(void) const
{
	return (_gradeToExecute);
}

void	AForm::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	if (_signed)
		throw std::runtime_error("Form already signed.");
	else
		_signed = true;
}

void	AForm::execute(Bureaucrat const &executor) const
{
	if (!_signed)
		throw NotSignedException();
	else if (executor.getGrade() > _gradeToExecute)
		throw GradeTooLowException();
}

std::ostream	&operator<<(std::ostream& os, const AForm& form)
{
	os << "Form: \"" << form.getName() << "\", Grade to sign: " << form.getGradeToSign() << ", Grade to execute: " << form.getGradeToExecute() << ", Signed: " << (form.getSigned() ? "true" : "false");
	return (os);
}
