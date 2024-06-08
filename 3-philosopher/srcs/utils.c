/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 18:36:59 by minabe            #+#    #+#             */
/*   Updated: 2023/07/09 04:42:03 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static bool	ft_isdigit(int c)
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
		if (!ft_isdigit(str[i]))
			return (-1);
		if ((nbr * 10 + (str[i] - '0')) / 10 != nbr)
			return (-1);
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	return ((int)nbr);
}

void	my_usleep(long long action_time)
{
	long long	start;

	start = get_time();
	while (get_time_diff(start) < action_time)
		usleep(100);
}

int	first(t_philo *philo_data)
{
	int	right;
	int	left;

	right = philo_data->id;
	left = (philo_data->id + 1) % philo_data->shered->num_of_philos;
	if (philo_data->shered->num_of_philos == 1)
		return (right);
	if (philo_data->id < philo_data->shered->num_of_philos - 1)
		return (right);
	else
		return (left);
}

int	second(t_philo *philo_data)
{
	int	right;
	int	left;

	right = philo_data->id;
	left = (philo_data->id + 1) % philo_data->shered->num_of_philos;
	if (philo_data->shered->num_of_philos == 1)
		return (right);
	if (philo_data->id < philo_data->shered->num_of_philos - 1)
		return (left);
	else
		return (right);
}
