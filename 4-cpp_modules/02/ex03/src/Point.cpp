/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:45:11 by minabe            #+#    #+#             */
/*   Updated: 2023/12/02 12:28:38 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void): _x(0), _y(0) {}

Point::Point(float const x, float const y): _x(x), _y(y) {}

Point::Point(const Point &src): _x(src._x), _y(src._y) {}

Point	&Point::operator=(Point const &rhs)
{
	if (this != &rhs)
	{
		const_cast<Fixed&>(this->_x) = rhs._x;
		const_cast<Fixed&>(this->_y) = rhs._y;
	}
	return (*this);
}

Point::~Point(void) {}

float	Point::getX(void) const
{
	return (this->_x.toFloat());
}

float	Point::getY(void) const
{
	return (this->_y.toFloat());
}
