/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 18:22:18 by minabe            #+#    #+#             */
/*   Updated: 2023/12/02 23:30:04 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap	scavTrap("ポッチャマ");
	// ScavTrap	scavTrap;

	scavTrap.attack("イシツブテ");
	scavTrap.takeDamage(10);
	scavTrap.beRepaired(100);
	scavTrap.guardGate();

	scavTrap.attack("ユキノオー");
	scavTrap.takeDamage(99);
	// scavTrap.takeDamage(100);
	scavTrap.beRepaired(100);
	scavTrap.guardGate();

	scavTrap.attack("ルカリオ");
	scavTrap.takeDamage(999999999);
	scavTrap.beRepaired(100);

	return (0);
}

__attribute__((destructor))
static void destructor(void)
{
	system("leaks -q ex01");
}
