/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FlagTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 18:08:36 by minabe            #+#    #+#             */
/*   Updated: 2023/12/01 23:02:29 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "ClapTrap.hpp"

class FlagTrap : virtual public ClapTrap
{
	public:
		FlagTrap(void);
		FlagTrap(std::string name);
		FlagTrap	&operator=(const FlagTrap &rhs);
		~FlagTrap(void);

		void	highFivesGuys(void);
};
