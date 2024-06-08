/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:06:46 by minabe            #+#    #+#             */
/*   Updated: 2023/12/07 14:44:13 by minabe           ###   ########.fr       */
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

class NotSignedException :public std::exception
{
	public:
		virtual const char	*what() const throw()
		{
			return ("Form is not signed.");
		}
};
