/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:29:11 by minabe            #+#    #+#             */
/*   Updated: 2023/12/03 20:26:31 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define DEFAULT "\033[0m"

class Brain
{
	protected:
		std::string	_ideas[100];

	public:
		Brain(void);
		Brain(const Brain &src);
		Brain	&operator=(const Brain &rhs);
		virtual ~Brain(void);

		std::string	getIdea(int index) const;
		void		setIdea(int index, const std::string &idea);
};
