/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:26:54 by minabe            #+#    #+#             */
/*   Updated: 2023/12/07 21:43:29 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void)
	: AForm("ShrubberyCreationForm", 145, 137), _target("Default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &name, const std::string &target)
	: AForm(name, 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
	: AForm(src), _target(src._target) {}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		_target = rhs._target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	AForm::execute(executor);
	std::ofstream	ofs(_target + "_shrubbery");
	if (!ofs)
		throw std::runtime_error("Failed to open file.");
	ofs << "      /\\      " << std::endl;
	ofs << "     /\\*\\     " << std::endl;
	ofs << "    /\\O\\*\\    " << std::endl;
	ofs << "   /*/\\/\\/\\   " << std::endl;
	ofs << "  /\\O\\/\\*\\/\\  " << std::endl;
	ofs << " /\\*\\/\\*\\/\\/\\ " << std::endl;
	ofs << "/\\O\\/\\/*/\\/O/\\" << std::endl;
	ofs << "      ||      " << std::endl;
	ofs << "      ||      " << std::endl;
	ofs << "      ||      " << std::endl;
	ofs << std::endl;
}

AForm	*ShrubberyCreationForm::create(const std::string &target)
{
	return (new ShrubberyCreationForm("ShrubberyCreationForm", target));
}
