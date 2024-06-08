/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 20:47:47 by minabe            #+#    #+#             */
/*   Updated: 2023/12/02 12:22:48 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

static void	processAndWriteFile(std::string s1, std::string s2, std::ifstream &inputFile, std::ofstream &outputFile);
static void	error(std::string message);

int	main(int argc, char **argv)
{
	std::string		filename;
	std::string		s1;
	std::string		s2;
	std::string		replace;

	if (argc != 4)
		error("Invalid number of arguments.");

	filename = argv[1];
	s1 = argv[2];
	if (s1 == "")
		error("Empty string is not allowed.");
	s2 = argv[3];
	replace = filename + ".replace";

	std::ifstream	inputFile(filename);
	if (!inputFile)
		error(" Could not open input file " + filename);

	std::ofstream	outputFile(replace);
	if (!outputFile)
		error(" Could not open output file " + replace);

	processAndWriteFile(s1, s2, inputFile, outputFile);
	inputFile.close();
	outputFile.close();
	return (0);
}

static void	processAndWriteFile(std::string s1, std::string s2, std::ifstream &inputFile, std::ofstream &outputFile)
{
	std::string	line;
	size_t		pos;

	while (std::getline(inputFile, line))
	{
		pos = line.find(s1);
		while (pos != std::string::npos)
		{
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos += s2.length();
			pos = line.find(s1, pos);
		}
		outputFile << line << std::endl;
	}
}

static void	error(std::string message)
{
	std::cerr << "Error: " << message << std::endl;
	exit(EXIT_FAILURE);
}
