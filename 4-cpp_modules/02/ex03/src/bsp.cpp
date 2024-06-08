/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:48:14 by minabe            #+#    #+#             */
/*   Updated: 2023/12/02 12:28:23 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

static float	dotProduct(float x1, float y1, float x2, float y2);
static void		computeVectors(Point const &a, Point const &b, float &v_x, float &v_y);

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	float v0_x, v0_y, v1_x, v1_y, v2_x, v2_y;

	computeVectors(a, c, v0_x, v0_y);
	computeVectors(b, a, v1_x, v1_y);
	computeVectors(a, point, v2_x, v2_y);

	float dot00 = dotProduct(v0_x, v0_y, v0_x, v0_y);
	float dot01 = dotProduct(v0_x, v0_y, v1_x, v1_y);
	float dot02 = dotProduct(v0_x, v0_y, v2_x, v2_y);
	float dot11 = dotProduct(v1_x, v1_y, v1_x, v1_y);
	float dot12 = dotProduct(v1_x, v1_y, v2_x, v2_y);

	float invDenom = (dot00 * dot11 - dot01 * dot01);
	if (invDenom == 0)
	{
		std::cerr << RED << "Error: Denominator is zero." << DEFAULT << std::endl;
		return false;
	}
	invDenom = 1.0f / invDenom;

	float u = (dot11 * dot02 - dot01 * dot12) * invDenom;
	float v = (dot00 * dot12 - dot01 * dot02) * invDenom;

	return (u >= 0) && (v >= 0) && (u + v <= 1);
}

static float	dotProduct(float x1, float y1, float x2, float y2)
{
	return x1 * x2 + y1 * y2;
}

static void	computeVectors(Point const &a, Point const &b, float &v_x, float &v_y)
{
	v_x = b.getX() - a.getX();
	v_y = b.getY() - a.getY();
}

