/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:09:38 by minabe            #+#    #+#             */
/*   Updated: 2023/12/03 16:26:58 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure();
		Cure(const Cure & src);
		Cure	&operator=(const Cure& rhs);
		virtual ~Cure();

		virtual AMateria*	clone() const;
		virtual void		use(ICharacter& target);
};
