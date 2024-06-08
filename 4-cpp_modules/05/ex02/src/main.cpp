/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 21:03:38 by minabe            #+#    #+#             */
/*   Updated: 2023/12/08 23:40:04 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	std::cout << "\n====NORMAL TEST====" << std::endl;
	try
	{
		Bureaucrat	king("King", 1);
		std::cout << king << std::endl;

		Bureaucrat	queen("Queen", 2);

		std::cout << "\n~~~~SHRUBBERY TEST~~~~" << std::endl;
		ShrubberyCreationForm	form("ShrubberyCreationForm", "Garden");
		std::cout << form << std::endl;

		king.signForm(form);
		queen.executeForm(form);

		std::cout << "\n~~~~ROBOTOMY TEST~~~~" << std::endl;
		RobotomyRequestForm	form2("RobotomyRequestForm", "King");
		std::cout << form2 << std::endl;

		king.signForm(form2);
		queen.executeForm(form2);

		std::cout << "\n~~~~PRESIDENTIAL TEST~~~~" << std::endl;
		PresidentialPardonForm	form3("PresidentialPardonForm", "King");
		std::cout << form3 << std::endl;
		king.signForm(form3);
		queen.executeForm(form3);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << DEFAULT << std::endl;
	}

	std::cout << "\n====ERROR TEST====" << std::endl;
	try
	{
		// Bureaucrat インスタンスの配列を作成
		Bureaucrat	benders[] = {
			Bureaucrat("Bender1", 146), // Shrubbery
			Bureaucrat("Bender2", 73),  // Robotomy
			Bureaucrat("Bender3", 26),  // Presidential
			Bureaucrat("Supreme Leader", 1) // 最高権限
		};

		Bureaucrat	executors[] = {
			Bureaucrat("Executor1", 138), // Shrubbery
			Bureaucrat("Executor2", 46),  // Robotomy
			Bureaucrat("Executor3", 6),   // Presidential
			Bureaucrat("Supreme Leader", 1) // 最高権限
		};
		int	testNum = 4;

		// ShrubberyCreationForm テスト
		std::cout << "\n~~~~SHRUBBERY TEST~~~~" << std::endl;

		for (int i = 0; i < testNum; i++)
		{
			ShrubberyCreationForm form("ShrubberyCreationForm", "Garden1");
			std::cout << form << std::endl;

			std::cout << "\n <" << benders[i] << ">" << std::endl;
			benders[i].signForm(form);

			for (int j = 0; j < testNum; j++)
			{
				std::cout << executors[j] << std::endl;
				executors[j].executeForm(form);
			}
		}

		// RobotomyRequestForm テスト
		std::cout << "\n~~~~ROBOTOMY TEST~~~~" << std::endl;

		for (int i = 0; i < testNum; i++)
		{
			RobotomyRequestForm form2("RobotomyRequestForm", "King");
			std::cout << form2 << std::endl;

			std::cout << "\n <" << benders[i] << ">" << std::endl;
			benders[i].signForm(form2);
			for (int j = 0; j < testNum; j++)
			{
				std::cout << executors[j] << std::endl;
				executors[j].executeForm(form2);
			}
		}

		// PresidentialPardonForm テスト
		std::cout << "\n~~~~PRESIDENTIAL TEST~~~~" << std::endl;

		for (int i = 0; i < testNum; i++)
		{
			PresidentialPardonForm form3("PresidentialPardonForm", "");
			std::cout << form3 << std::endl;

			std::cout << "\n <" << benders[i] << ">" << std::endl;
			benders[i].signForm(form3);

			for (int j = 0; j < testNum; j++)
			{
				std::cout << executors[j] << std::endl;
				executors[j].executeForm(form3);
			}
		}
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
	system("leaks -q ex02");
}
