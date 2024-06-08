/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 21:50:59 by minabe            #+#    #+#             */
/*   Updated: 2023/10/25 19:24:49 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>

# define ROWLEN 10

class Contact
{
	private:
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string	_phone_number;
		std::string	_darkest_secret;
	public:
		Contact(void);
		~Contact(void);
		void		setFirstName(const std::string &first_name);
		void		setLastName(const std::string &last_name);
		void		setNickname(const std::string &nickname);
		void		setPhoneNumber(const std::string &phone_number);
		void		setDarkestSecret(const std::string &darkest_secret);
		std::string	getFirstName(void) const;
		std::string	getLastName(void) const;
		std::string	getNickname(void) const;
		std::string	getPhoneNumber(void) const;
		std::string	getDarkestSecret(void) const;
};
