/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 21:56:16 by minabe            #+#    #+#             */
/*   Updated: 2023/12/02 12:15:15 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(int argc, char **argv)
{
	std::string	str;

	if (argc == 1)
		str = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; i < argc; i++)
			str += argv[i];
		std::transform(&str[0], &str[0] + str.size(), &str[0], ::toupper);
	}
	std::cout << str << std::endl;
	return (0);
}
