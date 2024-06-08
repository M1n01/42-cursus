/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 20:59:22 by minabe            #+#    #+#             */
/*   Updated: 2023/12/01 23:02:02 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FlagTrap.hpp"

class DiamondTrap : public ScavTrap, public FlagTrap
{
	private:
		std::string	_name;

	public:
		DiamondTrap(void);
		DiamondTrap(std::string name);
		DiamondTrap	&operator=(const DiamondTrap &rhs);
		~DiamondTrap(void);

		void	whoAmI(void);
};
