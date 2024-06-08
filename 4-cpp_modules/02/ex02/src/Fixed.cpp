/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 12:48:35 by minabe            #+#    #+#             */
/*   Updated: 2023/12/02 12:26:51 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void): _value(0)
{
	if (DEBUG)
		std::cout << BLUE << "Default constructor called" << DEFAULT << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
	if (DEBUG)
		std::cout << BLUE << "Copy constructor called" << DEFAULT << std::endl;
	*this = src;
}

Fixed::Fixed(const int value)
{
	if (DEBUG)
		std::cout << BLUE << "Int constructor called" << DEFAULT << std::endl;
	this->_value = value << this->_bits;
}

Fixed::Fixed(const float value)
{
	if (DEBUG)
		std::cout << BLUE << "Float constructor called" << DEFAULT << std::endl;
	this->_value = roundf(value * (1 << this->_bits));
}

Fixed	&Fixed::operator=(const Fixed &rhs)
{
	if (DEBUG)
		std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_value = rhs.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
	if (DEBUG)
		std::cout << YELLOW << "Destructor called" << DEFAULT << std::endl;
}

bool	Fixed::operator<(const Fixed &rhs)
{
	if (DEBUG)
		std::cout << "Less than operator called" << std::endl;
	return (this->_value < rhs._value);
}

bool	Fixed::operator>(const Fixed &rhs)
{
	if (DEBUG)
		std::cout << "Greater than operator called" << std::endl;
	return (this->_value > rhs._value);
}

bool	Fixed::operator<=(const Fixed &rhs)
{
	if (DEBUG)
		std::cout << "Less than or equal to operator called" << std::endl;
	return (this->_value <= rhs._value);
}

bool	Fixed::operator>=(const Fixed &rhs)
{
	if (DEBUG)
		std::cout << "Greater than or equal to operator called" << std::endl;
	return (this->_value >= rhs._value);
}

bool	Fixed::operator==(const Fixed &rhs)
{
	if (DEBUG)
		std::cout << "Equal to operator called" << std::endl;
	return (this->_value == rhs._value);
}

bool	Fixed::operator!=(const Fixed &rhs)
{
	if (DEBUG)
		std::cout << "Not equal to operator called" << std::endl;
	return (this->_value != rhs._value);
}

Fixed	Fixed::operator+(const Fixed &rhs)
{
	Fixed	result;

	if (DEBUG)
		std::cout << "Addition operator called" << std::endl;
	result._value = this->_value + rhs._value;
	return (result);
}

Fixed	Fixed::operator-(const Fixed &rhs)
{
	Fixed	result;

	if (DEBUG)
		std::cout << "Subtraction operator called" << std::endl;
	result._value = this->_value - rhs._value;
	return (result);
}

Fixed	Fixed::operator*(const Fixed &rhs)
{
	long	temp;
	Fixed	result;

	if (DEBUG)
		std::cout << "Multiplication operator called" << std::endl;
	temp = (long)(this->_value) * (long)(rhs._value) >> _bits;
	if (temp > INT_MAX || temp < INT_MIN)
	{
		std::cerr << RED << "Error: Multiplication overflow" << DEFAULT << std::endl;
		return (Fixed());
	}
	result._value = (int)temp;
	return (result);
}

Fixed	Fixed::operator/(const Fixed &rhs)
{
	Fixed	result;

	if (DEBUG)
		std::cout << "Division operator called" << std::endl;
	if (rhs._value == 0)
	{
		std::cerr << RED << "Error: Zero divide detected" << DEFAULT << std::endl;
		return (Fixed(0));
	}
	result._value = (this->_value << _bits) / rhs._value;
	return (result);
}

Fixed	&Fixed::operator++(void)
{
	if (DEBUG)
		std::cout << "Pre-increment operator called" << std::endl;
	this->_value++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);

	if (DEBUG)
		std::cout << "Post-increment operator called" << std::endl;
	this->_value++;
	return (tmp);
}

Fixed	&Fixed::operator--(void)
{
	if (DEBUG)
		std::cout << "Pre-decrement operator called" << std::endl;
	this->_value--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);

	if (DEBUG)
		std::cout << "Post-decrement operator called" << std::endl;
	this->_value--;
	return (tmp);
}

std::ostream	&operator<<(std::ostream &os, const Fixed &rhs)
{
	os << rhs.toFloat();
	return (os);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (DEBUG)
		std::cout << "Min function called" << std::endl;
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (DEBUG)
		std::cout << "Min function called" << std::endl;
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (DEBUG)
		std::cout << "Max function called" << std::endl;
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (DEBUG)
		std::cout << "Max function called" << std::endl;
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}

int	Fixed::getRawBits(void) const
{
	if (DEBUG)
		std::cout << "getRawBits member function called" << std::endl;
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
