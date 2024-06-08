/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 21:03:38 by minabe            #+#    #+#             */
/*   Updated: 2023/12/08 23:39:02 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	std::cout << "\n====NORMAL TEST====" << std::endl;
	try
	{
		Bureaucrat	king("King", 1);
		std::cout << king << std::endl;

		Bureaucrat	queen("Queen", 2);
		std::cout << queen << std::endl;

		Intern	someRandomIntern;

		std::cout << "\n~~~~SHRUBBERY TEST~~~~" << std::endl;
		AForm	*scf = someRandomIntern.makeForm("shrubbery creation", "Garden");
		std::cout << *scf << std::endl;

		king.signForm(*scf);
		queen.executeForm(*scf);

		delete scf;

		std::cout << "\n~~~~ROBOTOMY TEST~~~~" << std::endl;
		AForm	*rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		std::cout << *rrf << std::endl;

		king.signForm(*rrf);
		queen.executeForm(*rrf);

		delete rrf;

		std::cout << "\n~~~~PRESIDENTIAL TEST~~~~" << std::endl;
		AForm	*ppf = someRandomIntern.makeForm("presidential pardon", "Bender");
		std::cout << *ppf << std::endl;
		king.signForm(*ppf);
		queen.executeForm(*ppf);

		delete ppf;
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

		Intern	someRandomIntern;

		// ShrubberyCreationForm テスト
		std::cout << "\n~~~~SHRUBBERY TEST~~~~" << std::endl;

		for (int i = 0; i < testNum; i++)
		{
			AForm	*scf = someRandomIntern.makeForm("shrubbery creation", "Garden");
			std::cout << *scf << std::endl;

			std::cout << "\n <" << benders[i] << ">" << std::endl;
			benders[i].signForm(*scf);

			for (int j = 0; j < testNum; j++)
			{
				std::cout << executors[j] << std::endl;
				executors[j].executeForm(*scf);
			}
			delete scf;
		}


		// RobotomyRequestForm テスト
		std::cout << "\n~~~~ROBOTOMY TEST~~~~" << std::endl;

		for (int i = 0; i < testNum; i++)
		{
			AForm	*rrf = someRandomIntern.makeForm("robotomy request", "Bender");
			std::cout << *rrf << std::endl;

			std::cout << "\n <" << benders[i] << ">" << std::endl;
			benders[i].signForm(*rrf);
			for (int j = 0; j < testNum; j++)
			{
				std::cout << executors[j] << std::endl;
				executors[j].executeForm(*rrf);
			}
			delete rrf;
		}


		// PresidentialPardonForm テスト
		std::cout << "\n~~~~PRESIDENTIAL TEST~~~~" << std::endl;

		for (int i = 0; i < testNum; i++)
		{
			AForm	*ppf = someRandomIntern.makeForm("presidential pardon", "Bender");
			std::cout << *ppf << std::endl;

			std::cout << "\n <" << benders[i] << ">" << std::endl;
			benders[i].signForm(*ppf);

			for (int j = 0; j < testNum; j++)
			{
				std::cout << executors[j] << std::endl;
				executors[j].executeForm(*ppf);
			}
			delete ppf;
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
	system("leaks -q ex03");
}
