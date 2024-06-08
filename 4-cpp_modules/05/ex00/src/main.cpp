/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 21:03:38 by minabe            #+#    #+#             */
/*   Updated: 2023/12/07 14:02:51 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "exception.hpp"

int	main(void)
{
	std::cout << "\n====NORMAL TEST====" << std::endl;
	try
	{
		Bureaucrat	normal("Normal", 42);
		std::cout << normal << std::endl;

		// copy constructor
		Bureaucrat	normal1(normal);
		Bureaucrat	normal2(normal);

		normal1.incrementGrade();
		std::cout << normal1 << std::endl;

		normal2.decrementGrade();
		std::cout << normal2 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << DEFAULT << std::endl;
	}

	try
	{
		Bureaucrat	high("High", 0); // 例外を投げる
		std::cout << high << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << DEFAULT << std::endl;
	}

	try
	{
		Bureaucrat	low("Low", 151); // 例外を投げる
		std::cout << low << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << DEFAULT << std::endl;
	}

	std::cout << "\n====LOWEST TEST====" << std::endl;
	try
	{
		// default constructor
		Bureaucrat	lowest;
		std::cout << lowest << std::endl;
		lowest.decrementGrade(); // 例外を投げる
		std::cout << lowest << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << DEFAULT << std::endl;
	}

	std::cout << "\n====HIGHEST TEST====" << std::endl;
	try
	{
		Bureaucrat	highest("Highest", 1);
		std::cout << highest << std::endl;
		highest.incrementGrade(); // 例外を投げる
		std::cout << highest << std::endl;
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
	system("leaks -q ex00");
}
