/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 21:03:38 by minabe            #+#    #+#             */
/*   Updated: 2023/12/07 14:13:05 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "exception.hpp"

int	main(void)
{
	std::cout << "\n====NORMAL TEST====" << std::endl;
	try
	{
		Form	form("Form", 42, 42);
		std::cout << form << std::endl;

		// default constructor
		Form	confidentialForm;
		std::cout << confidentialForm << std::endl;


		Bureaucrat	normal("Normal", 42);
		std::cout << normal << std::endl;
		Bureaucrat	normal2("Normal2", 42);
		std::cout << normal2 << std::endl;

		normal.signForm(form);
		std::cout << form << std::endl;
		normal.signForm(confidentialForm);
		std::cout << confidentialForm << std::endl;

		normal2.signForm(form);
		std::cout << form << std::endl;

		std::cout << "\n====COPY TEST====" << std::endl;
		Form	copyForm(form);
		std::cout << copyForm << std::endl;
		normal2.signForm(copyForm);
		std::cout << copyForm << std::endl;


		std::cout << "\n====ERROR TEST====" << std::endl;
		// Form	errorForm("ErrorForm", 0, 42);
		// std::cout << errorForm << std::endl;

		Form	errorForm2("ErrorForm", 1, 151);
		std::cout << errorForm2 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << DEFAULT << std::endl;
	}

	std::cout << "\n====LOWEST TEST====" << std::endl;
	try
	{
		Form	form("Form", 42, 42);
		std::cout << form << std::endl;

		// default constructor
		Form	confidentialForm;
		std::cout << confidentialForm << std::endl;

		Bureaucrat	lowest("Lowest", 150);
		std::cout << lowest << std::endl;
		lowest.signForm(confidentialForm);
		std::cout << confidentialForm << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << DEFAULT << std::endl;
	}

	std::cout << "\n====HIGHEST TEST====" << std::endl;
	try
	{
		Form	form("Form", 42, 42);
		std::cout << form << std::endl;
		Form	confidentialForm;
		std::cout << confidentialForm << std::endl;

		Bureaucrat	highest("Highest", 1);
		std::cout << highest << std::endl;
		highest.signForm(confidentialForm);
		std::cout << confidentialForm << std::endl;
		highest.signForm(form);
		std::cout << form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << DEFAULT << std::endl;
	}

	return (0);
}

__attribute__((destructor))
static void destructor(void)
{
	system("leaks -q ex01");
}
