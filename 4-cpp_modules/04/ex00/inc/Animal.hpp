/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 23:05:25 by minabe            #+#    #+#             */
/*   Updated: 2023/12/05 15:25:27 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define DEFAULT "\033[0m"

class Animal
{
	protected:
		std::string	_type;

	public:
		Animal(void);
		Animal(const Animal &src);
		Animal	&operator=(const Animal &rhs);
		virtual ~Animal(void);

		std::string	getType(void) const;
		virtual void		makeSound(void) const;
};
