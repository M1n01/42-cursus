/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 10:57:14 by minabe            #+#    #+#             */
/*   Updated: 2023/04/26 12:25:54 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static void	error(void);
static int	check_sign(char c, size_t *i);

int	ft_atoi(const char *str)
{
	int			sign;
	size_t		i;
	size_t		len;
	long long	nbr;

	len = ft_strlen(str);
	i = 0;
	sign = check_sign(str[i], &i);
	nbr = 0;
	while (i < len)
	{
		if (!ft_isdigit(str[i]))
			error();
		nbr = nbr * 10 + (str[i] - '0');
		if (nbr > (long long)INT_MAX + 1)
			error();
		i++;
	}
	nbr *= sign;
	if (nbr < INT_MIN || INT_MAX < nbr)
		error();
	return ((int)nbr);
}

static int	check_sign(char c, size_t *i)
{
	if (c == '-' || c == '+')
	{
		(*i)++;
		if (c == '-')
			return (-1);
	}
	return (1);
}

static void	error(void)
{
	ft_printf("Error\n");
	exit(1);
	return ;
}
