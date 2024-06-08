/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:14:07 by minabe            #+#    #+#             */
/*   Updated: 2023/12/02 12:16:19 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

static void	cmdLoop(PhoneBook &phoneBook);
static void	inputContact(Contact &contact);
static void	outputPhoneBook(PhoneBook &phoneBook);

int	main(void)
{
	PhoneBook	phoneBook;

	cmdLoop(phoneBook);
	return (0);
}

__attribute__((destructor))
static void destructor(void)
{
	system("leaks -q phoneBook");
}

static void	cmdLoop(PhoneBook &phoneBook)
{
	std::string	cmd;
	Contact		contact;

	while (true)
	{
		std::cout << "Enter a command: ";
		if (!std::getline(std::cin, cmd) || std::cin.eof())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			break ;
		}
		if (cmd == "ADD")
		{
			inputContact(contact);
			phoneBook.addContact(contact);
		}
		else if (cmd == "SEARCH")
		{
			outputPhoneBook(phoneBook);
			if (!phoneBook.searchContacts())
			{
				if (std::cin.eof())
					break ;
				continue ;
			}
		}
		else if (cmd == "EXIT")
			break ;
		else
			std::cout << RED << "Invalid command!" << DEFAULT << std::endl;
	}
}

static void	inputContact(Contact &contact)
{
	std::string	input;

	std::cout << "======= Enter Contact =======\n";
	std::cout << "[First name] => ";
	getline(std::cin, input);
	contact.setFirstName(input);
	std::cout << "[Last name] => ";
	getline(std::cin, input);
	contact.setLastName(input);
	std::cout << "[Nickname] => ";
	getline(std::cin, input);
	contact.setNickname(input);
	std::cout << "[Phone number] => ";
	getline(std::cin, input);
	contact.setPhoneNumber(input);
	std::cout << "[Darkest secret] => ";
	getline(std::cin, input);
	contact.setDarkestSecret(input);
	std::cout << "=============================\n";
}

static std::string	formatString(const std::string &str, size_t len)
{
	if (str.length() > len)
		return (str.substr(0, len - 1) + ".");
	else if (str.length() < len)
		return (std::string(len - str.length(), ' ') + str);
	else
		return (str);
}

static void	displayContactRow(const Contact &contact, int index)
{
	std::cout << "|" << std::string(ROWLEN - 1, ' ') << index << "|";
	std::cout << formatString(contact.getFirstName(), ROWLEN) << "|";
	std::cout << formatString(contact.getLastName(), ROWLEN) << "|";
	std::cout << formatString(contact.getNickname(), ROWLEN) << "|" << std::endl;

}

static void	outputPhoneBook(PhoneBook &phoneBook)
{
	std::string	header;

	header = "|Index     |First name|Last name |Nickname  |";
	std::cout << header << std::endl;
	for (int i = 0; i < phoneBook.getNumContacts(); i++)
		displayContactRow(phoneBook.getContact(i), i + 1);
}
