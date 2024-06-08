/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 12:48:35 by minabe            #+#    #+#             */
/*   Updated: 2023/12/02 12:25:41 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void): _value(0)
{
	std::cout << BLUE << "Default constructor called" << DEFAULT << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << BLUE << "Copy constructor called" << DEFAULT << std::endl;
	*this = src;
}

Fixed::Fixed(const int value)
{
	std::cout << BLUE << "Int constructor called" << DEFAULT << std::endl;
	this->_value = value << this->_bits;
}

Fixed::Fixed(const float value)
{
	std::cout << BLUE << "Float constructor called" << DEFAULT << std::endl;
	this->_value = roundf(value * (1 << this->_bits));
}

Fixed::~Fixed(void)
{
	std::cout << YELLOW << "Destructor called" << DEFAULT << std::endl;
}

Fixed	&Fixed::operator=(const Fixed &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_value = rhs.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_value / (1 << this->_bits));
}

int		Fixed::toInt(void) const
{
	return (this->_value >> this->_bits);
}

std::ostream	&operator<<(std::ostream &os, const Fixed &rhs)
{
	os << rhs.toFloat();
	return (os);
}
