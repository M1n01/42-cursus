/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 09:38:38 by minabe            #+#    #+#             */
/*   Updated: 2023/06/27 11:50:24 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	take_forks(t_philo *philo_data)
{
	pthread_mutex_lock(&philo_data->shered.log);
	pthread_mutex_lock(&philo_data->shered.forks[first(philo_data)]);
	print_time_diff(philo_data->shered.start_time);
	printf("%d has taken a fork\n", philo_data->id + 1);
	pthread_mutex_unlock(&philo_data->shered.log);
	pthread_mutex_lock(&philo_data->shered.log);
	pthread_mutex_lock(&philo_data->shered.forks[second(philo_data)]);
	print_time_diff(philo_data->shered.start_time);
	printf("%d has taken a fork\n", philo_data->id + 1);
	pthread_mutex_unlock(&philo_data->shered.log);
	// print_log(philo_data, "has taken a fork", philo_data->shered.forks[first(philo_data)]);
	// print_log(philo_data, "has taken a fork", philo_data->shered.forks[second(philo_data)]);
}

void	put_forks(t_philo *philo_data)
{
	pthread_mutex_unlock(&philo_data->shered.forks[first(philo_data)]);
	pthread_mutex_unlock(&philo_data->shered.forks[second(philo_data)]);
}

void	eating(t_philo *philo_data)
{
	// print_time_diff(philo_data->shered.start_time);
	// printf("%d is eating\n", philo_data->id + 1);
	// print_log(philo_data, "is eating", philo_data->shered.log);
	print_log(philo_data, "is eating", philo_data->shered.log);
	my_usleep(philo_data->shered.time_to_eat * 1000);
	pthread_mutex_lock(&philo_data->shered.log);
	philo_data->eat_count++;
	philo_data->last_eat_time = get_time();
	pthread_mutex_unlock(&philo_data->shered.log);
}

void	sleeping(t_philo *philo_data)
{
	pthread_mutex_lock(&philo_data->shered.log);
	print_time_diff(philo_data->shered.start_time);
	printf("%d is sleeping\n", philo_data->id + 1);
	pthread_mutex_unlock(&philo_data->shered.log);
	my_usleep(philo_data->shered.time_to_sleep * 1000);
}

void	thinking(t_philo *philo_data)
{
	// フォークが空くまでthinkする
	pthread_mutex_lock(&philo_data->shered.log);
	print_time_diff(philo_data->shered.start_time);
	printf("%d is thinking\n", philo_data->id + 1);
	pthread_mutex_unlock(&philo_data->shered.log);
}
