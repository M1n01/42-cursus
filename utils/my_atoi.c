/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 18:36:59 by minabe            #+#    #+#             */
/*   Updated: 2023/06/24 18:54:11 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static bool	isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (true);
	return (false);
}

int	my_atoi(const char *str)
{
	size_t		i;
	long long	nbr;

	i = 0;
	nbr = 0;
	while (str[i] != '\0')
	{
		if (!isdigit(str[i]))
			return (-1);
		if ((nbr * 10 + (str[i] - '0')) / 10 != nbr)
			return (-1);
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	return ((int)nbr);
}
