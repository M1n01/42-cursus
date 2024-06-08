/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 09:38:38 by minabe            #+#    #+#             */
/*   Updated: 2023/07/10 09:55:18 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	take_forks(t_philo *philo_data)
{
	pthread_mutex_lock(&philo_data->shered->forks[first(philo_data)]);
	print_log(philo_data, "has taken a fork");
	if (first(philo_data) == second(philo_data))
	{
		pthread_mutex_unlock(&philo_data->shered->forks[first(philo_data)]);
		return (EXIT_FAILURE);
	}
	pthread_mutex_lock(&philo_data->shered->forks[second(philo_data)]);
	print_log(philo_data, "has taken a fork");
	return (EXIT_SUCCESS);
}

static void	put_forks(t_philo *philo_data)
{
	pthread_mutex_unlock(&philo_data->shered->forks[first(philo_data)]);
	pthread_mutex_unlock(&philo_data->shered->forks[second(philo_data)]);
	pthread_mutex_lock(&philo_data->shered->mutex);
	philo_data->is_eating = false;
	pthread_mutex_unlock(&philo_data->shered->mutex);
}

int	eating(t_philo *philo_data)
{
	if (take_forks(philo_data))
		return (EXIT_FAILURE);
	pthread_mutex_lock(&philo_data->shered->mutex);
	philo_data->is_eating = true;
	philo_data->eat_count++;
	philo_data->last_eat_time = get_time();
	pthread_mutex_unlock(&philo_data->shered->mutex);
	print_log(philo_data, "is eating");
	my_usleep(philo_data->shered->eat_time * 1000);
	put_forks(philo_data);
	return (EXIT_SUCCESS);
}

void	sleeping(t_philo *philo_data)
{
	print_log(philo_data, "is sleeping");
	my_usleep(philo_data->shered->sleep_time * 1000);
}

void	thinking(t_philo *philo_data)
{
	print_log(philo_data, "is thinking");
}
