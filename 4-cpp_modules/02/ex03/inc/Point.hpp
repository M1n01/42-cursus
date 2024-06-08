/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:45:08 by minabe            #+#    #+#             */
/*   Updated: 2023/11/24 15:27:05 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "Fixed.hpp"

class Point
{
	private:
		Fixed const	_x;
		Fixed const	_y;
	public:
		Point(void);
		Point(float const x, float const y);
		Point(const Point &src);
		Point	&operator=(Point const &rhs);
		~Point(void);

		float	getX(void) const;
		float	getY(void) const;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);
