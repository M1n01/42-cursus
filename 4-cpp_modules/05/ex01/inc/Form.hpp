/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:36:37 by minabe            #+#    #+#             */
/*   Updated: 2023/12/07 17:22:20 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <string>
# include "exception.hpp"
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_signed;
		const unsigned int	_gradeToSign;
		const unsigned int	_gradeToExecute;

	public:
		Form(void);
		Form(std::string const &name, unsigned int gradeToSign, int gradeToExecute);
		Form(Form const &src);
		Form	&operator=(Form const &rhs);
		~Form(void);

		const std::string	&getName(void) const;
		bool				getSigned(void) const;
		unsigned int		getGradeToSign(void) const;
		unsigned int		getGradeToExecute(void) const;

		void				beSigned(Bureaucrat const &bureaucrat);
};

std::ostream	&operator<<(std::ostream& os, const Form& form);
