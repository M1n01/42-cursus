/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 21:15:28 by minabe            #+#    #+#             */
/*   Updated: 2023/12/02 12:23:51 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << YELLOW << "[ WARNING ]\nI think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << DEFAULT << std::endl;
}

void	Harl::error(void)
{
	std::cout << RED << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now." << DEFAULT << std::endl;
}

static int	getLevel(std::string level)
{
	std::string			levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int					levelIndex = 0;

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			levelIndex = i;
			return (levelIndex);
		}
	}
	return (-1);
}

void	Harl::filterComplaints(std::string level)
{
	std::string			levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int					levelIndex = getLevel(level);

	switch (levelIndex)
	{
		case DEBUG:
			debug();
		case INFO:
			info();
		case WARNING:
			warning();
		case ERROR:
			error();
			break;
		default:
			std::cout << RED << "Invalid level." << DEFAULT << std::endl;
			break;
	}
}
