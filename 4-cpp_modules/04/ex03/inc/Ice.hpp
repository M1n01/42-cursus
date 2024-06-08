/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:10:30 by minabe            #+#    #+#             */
/*   Updated: 2023/12/03 16:26:49 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice();
		Ice(const Ice & src);
		Ice	&operator=(const Ice& rhs);
		virtual ~Ice();

		virtual AMateria*	clone() const;
		virtual void		use(ICharacter& target);
};
