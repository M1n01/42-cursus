/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:18:20 by minabe            #+#    #+#             */
/*   Updated: 2023/12/03 21:31:01 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		static const int	MAX_UMATERIAS = 10; // unequipされたMateriasの最大数

		std::string	_name;
		AMateria*	_inventory[4];
		int			_unequipCount;
		AMateria*	_unequippedMaterias[MAX_UMATERIAS];

	public:
		Character(std::string const & name);
		Character(const Character & src);
		Character&	operator=(const Character& rhs);
		virtual ~Character();

		virtual std::string const &	getName() const;
		virtual void				equip(AMateria* m);
		virtual void				unequip(int idx);
		virtual void				use(int idx, ICharacter& target);
};
