/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 20:50:28 by minabe            #+#    #+#             */
/*   Updated: 2023/11/12 13:53:59 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define DEFAULT "\033[0m"

enum Level
{
	DEBUG,
	INFO,
	WARNING,
	ERROR,
	INVALID
};

class Harl
{
	private:
		typedef void	(Harl::*ComplainFunction)(void);
		void			debug(void);
		void			info(void);
		void			warning(void);
		void			error(void);
	public:
		void			filterComplaints(std::string level);
};
