/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 23:05:25 by minabe            #+#    #+#             */
/*   Updated: 2023/12/02 15:47:47 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define DEFAULT "\033[0m"

class AAnimal
{
	protected:
		std::string	_type;

	public:
		AAnimal(void);
		AAnimal(const AAnimal &src);
		AAnimal	&operator=(const AAnimal &rhs);
		virtual ~AAnimal(void);

		virtual std::string	getType(void) const;
		virtual void		makeSound(void) const = 0;
};
