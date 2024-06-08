/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 18:22:18 by minabe            #+#    #+#             */
/*   Updated: 2023/12/02 23:48:39 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap	diamondTrap("ルカリオ");
	// DiamondTrap	diamondTrap;

	diamondTrap.attack("エルフーン");
	diamondTrap.takeDamage(10);
	diamondTrap.beRepaired(100);
	diamondTrap.guardGate();
	diamondTrap.highFivesGuys();
	diamondTrap.whoAmI();

	diamondTrap.attack("メタモン");
	diamondTrap.takeDamage(99);
	// diamondTrap.takeDamage(100);
	diamondTrap.beRepaired(100);
	diamondTrap.guardGate();
	diamondTrap.highFivesGuys();
	diamondTrap.whoAmI();

	diamondTrap.attack("キノガッサ");
	diamondTrap.takeDamage(999999999);
	diamondTrap.beRepaired(100);
	diamondTrap.guardGate();
	diamondTrap.highFivesGuys();
	diamondTrap.whoAmI();

	return (0);
}

__attribute__((destructor))
static void destructor(void)
{
	system("leaks -q ex03");
}
