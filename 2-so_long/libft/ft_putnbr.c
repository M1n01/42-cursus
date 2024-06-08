/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:19:01 by minabe            #+#    #+#             */
/*   Updated: 2022/06/07 12:37:09 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

ssize_t	ft_putnbr(long long n)
{
	ssize_t	res;

	res = 0;
	if (n == INT_MIN)
	{
		n /= 10;
		res += ft_putnbr(n);
		res += ft_putchar('8');
		return (res);
	}
	if (n < 0)
	{
		res += ft_putchar('-');
		n *= -1;
		res += ft_putnbr(n);
		return (res);
	}
	if (n < 10)
	{
		res += ft_putchar(n + '0');
		return (res);
	}
	res += ft_putnbr(n / 10);
	res += ft_putchar(n % 10 + '0');
	return (res);
}
