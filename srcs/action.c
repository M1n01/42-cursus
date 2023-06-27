/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 09:38:38 by minabe            #+#    #+#             */
/*   Updated: 2023/06/28 00:58:13 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	take_forks(t_philo *philo_data)
{
	pthread_mutex_lock(&philo_data->shered.forks[first(philo_data)]);
	print_log(philo_data, "has taken a fork");
	pthread_mutex_lock(&philo_data->shered.forks[second(philo_data)]);
	print_log(philo_data, "has taken a fork");
}

void	put_forks(t_philo *philo_data)
{
	pthread_mutex_unlock(&philo_data->shered.forks[first(philo_data)]);
	pthread_mutex_unlock(&philo_data->shered.forks[second(philo_data)]);
}

void	eating(t_philo *philo_data)
{
	take_forks(philo_data);
	print_log(philo_data, "is eating");
	my_usleep(philo_data->shered.time_to_eat * 1000);
	pthread_mutex_lock(&philo_data->shered.mutex);
	philo_data->eat_count++;
	philo_data->last_eat_time = get_time();
	pthread_mutex_unlock(&philo_data->shered.mutex);
	put_forks(philo_data);
}

void	sleeping(t_philo *philo_data)
{
	print_log(philo_data, "is sleeping");
	my_usleep(philo_data->shered.time_to_sleep * 1000);
}

void	thinking(t_philo *philo_data)
{
	print_log(philo_data, "is thinking");
}
