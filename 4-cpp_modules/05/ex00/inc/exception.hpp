/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exception.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:06:46 by minabe            #+#    #+#             */
/*   Updated: 2023/12/05 14:07:43 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <exception>

class GradeTooHighException : public std::exception
{
	public:
		virtual const char	*what() const throw()
		{
			return ("Grade is too high.");
		}
};

class GradeTooLowException : public std::exception
{
	public:
		virtual const char	*what() const throw()
		{
			return ("Grade is too low.");
		}
};
