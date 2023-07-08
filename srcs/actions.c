/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 09:38:38 by minabe            #+#    #+#             */
/*   Updated: 2023/07/08 16:00:21 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	take_forks(t_philo *philo_data)
{
	if (philo_data->id % 2 == 1)
		usleep(10);
	pthread_mutex_lock(&philo_data->shered->forks[first(philo_data)]);
	print_log(philo_data, "has taken a fork");
	if (philo_data->shered->num_of_philos == 1)
		my_usleep(philo_data->shered->death_time * 10000);
	pthread_mutex_lock(&philo_data->shered->forks[second(philo_data)]);
	print_log(philo_data, "has taken a fork");
	pthread_mutex_lock(&philo_data->shered->mutex);
	philo_data->is_eating = true;
	pthread_mutex_unlock(&philo_data->shered->mutex);
}

static void	put_forks(t_philo *philo_data)
{
	pthread_mutex_unlock(&philo_data->shered->forks[first(philo_data)]);
	pthread_mutex_unlock(&philo_data->shered->forks[second(philo_data)]);
	pthread_mutex_lock(&philo_data->shered->mutex);
	philo_data->is_eating = false;
	pthread_mutex_unlock(&philo_data->shered->mutex);
}

void	eating(t_philo *philo_data)
{
	take_forks(philo_data);
	print_log(philo_data, "is eating");
	my_usleep(philo_data->shered->eat_time * 1000);
	pthread_mutex_lock(&philo_data->shered->mutex);
	philo_data->eat_count++;
	philo_data->last_eat_time = get_time();
	pthread_mutex_unlock(&philo_data->shered->mutex);
	put_forks(philo_data);
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
