/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 18:22:18 by minabe            #+#    #+#             */
/*   Updated: 2023/12/02 23:17:43 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	clapTrap("ピカチュウ");
	// ClapTrap	clapTrap;

	clapTrap.attack("ゲンガー");
	clapTrap.takeDamage(2);
	clapTrap.beRepaired(10);

	clapTrap.attack("ミカルゲ");
	clapTrap.takeDamage(9);
	// clapTrap.takeDamage(10);
	clapTrap.beRepaired(10);

	clapTrap.attack("ミミッキュ");
	clapTrap.takeDamage(999999999);
	clapTrap.beRepaired(10);

	return (0);
}

__attribute__((destructor))
static void destructor(void)
{
	system("leaks -q ex00");
}
