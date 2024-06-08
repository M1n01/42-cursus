/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:49:47 by minabe            #+#    #+#             */
/*   Updated: 2023/12/07 21:12:43 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class Intern
{
	private:
		typedef AForm *(*FormCreator)(const std::string &);

		static const int			numForms = 3;
		static const std::string	formNames[numForms];
		static FormCreator			formCreators[numForms];

	public:
		Intern(void);
		Intern(Intern const &src);
		Intern	&operator=(Intern const &rhs);
		~Intern(void);

		AForm		*makeForm(std::string const &formName, std::string const &target) const;
		static void	initializeFormCreators(void);
};
