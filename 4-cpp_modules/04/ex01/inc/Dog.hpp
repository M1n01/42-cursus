/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 22:13:36 by minabe            #+#    #+#             */
/*   Updated: 2023/12/03 16:01:44 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain	*_brain;

	public:
		Dog(void);
		Dog(const Dog &src);
		Dog	&operator=(const Dog &rhs);
		~Dog(void);

		void	makeSound(void) const;
		Brain	*getBrain(void) const;
};
