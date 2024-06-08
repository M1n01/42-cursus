/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 20:47:47 by minabe            #+#    #+#             */
/*   Updated: 2023/11/24 15:19:12 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int main(void)
{
	Point	a(0.0f, 0.0f);
	Point	b(0.0f, 1.0f);
	Point	c(1.0f, 1.0f);

	Point	p1(0.1f, 0.1f);
	Point	p2(0.5f, 0.5f);
	Point	p3(-0.1f, -0.1f);
	Point	p4(1.0f, 1.0f);

	std::cout << "p1 is " << (bsp(a, b, c, p1) ? "inside" : "outside") << " the triangle." << std::endl;
	std::cout << "p2 is " << (bsp(a, b, c, p2) ? "inside" : "outside") << " the triangle." << std::endl;
	std::cout << "p3 is " << (bsp(a, b, c, p3) ? "inside" : "outside") << " the triangle." << std::endl;
	std::cout << "p4 is " << (bsp(a, b, c, p4) ? "inside" : "outside") << " the triangle." << std::endl;
	return (0);
}
