/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:13:24 by minabe            #+#    #+#             */
/*   Updated: 2023/12/02 12:15:45 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : _numContacts(0) {}

void	PhoneBook::addContact(const Contact &contact)
{
	if (_numContacts == MAX_CONTACTS)
	{
		for (int i = 0; i < MAX_CONTACTS - 1; i++)
			_contacts[i] = _contacts[i + 1];
		_contacts[MAX_CONTACTS - 1] = contact;
	}
	else
	{
		_contacts[_numContacts] = contact;
		_numContacts++;
	}
}

void	outputContact(Contact &contact)
{
	std::cout << "======= Contact Information =======\n";
	std::cout << "[First name] => " << contact.getFirstName() << std::endl;
	std::cout << "[Last name] => " << contact.getLastName() << std::endl;
	std::cout << "[Nickname] => " << contact.getNickname() << std::endl;
	std::cout << "[Phone number] => " << contact.getPhoneNumber() << std::endl;
	std::cout << "[Darkest secret] => " << contact.getDarkestSecret() << std::endl;
	std::cout << "===================================\n";
}

bool	PhoneBook::searchContacts(void)
{
	std::string	input;
	int			index;

	std::cout << "Enter an index: ";
	if (!std::getline(std::cin, input))
		return (false);
	std::istringstream iss(input);
	if (!(iss >> index) || index < 1 || _numContacts < index)
	{
		std::cout << RED << "Invalid index!" << DEFAULT << std::endl;
		return (false);
	}
	outputContact(_contacts[index - 1]);
	return (true);
}

int	PhoneBook::getNumContacts(void) const
{
	return (_numContacts);
}

Contact	PhoneBook::getContact(int index) const
{
	return (_contacts[index]);
}
