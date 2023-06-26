/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 09:38:38 by minabe            #+#    #+#             */
/*   Updated: 2023/06/26 17:21:04 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	take_forks(t_philo *philo_data)
{
	pthread_mutex_lock(&philo_data->data.log);
	pthread_mutex_lock(&philo_data->data.forks[first(philo_data)]);
	print_time_diff(philo_data->data.start_time);
	printf("%d has taken a fork\n", philo_data->id + 1);
	pthread_mutex_lock(&philo_data->data.forks[second(philo_data)]);
	print_time_diff(philo_data->data.start_time);
	printf("%d has taken a fork\n", philo_data->id + 1);
	pthread_mutex_unlock(&philo_data->data.log);
}

void	put_forks(t_philo *philo_data)
{
	pthread_mutex_unlock(&philo_data->data.forks[first(philo_data)]);
	pthread_mutex_unlock(&philo_data->data.forks[second(philo_data)]);
}

void	eating(t_philo *philo_data)
{
	pthread_mutex_lock(&philo_data->data.log);
	print_time_diff(philo_data->data.start_time);
	printf("%d is eating\n", philo_data->id + 1);
	philo_data->eat_count++;
	pthread_mutex_unlock(&philo_data->data.log);
	my_usleep(philo_data->data.time_to_eat * 1000);
	pthread_mutex_lock(&philo_data->data.log);
	philo_data->last_eat_time = get_time();
	pthread_mutex_unlock(&philo_data->data.log);
}

void	sleeping(t_philo *philo_data)
{
	pthread_mutex_lock(&philo_data->data.log);
	print_time_diff(philo_data->data.start_time);
	printf("%d is sleeping\n", philo_data->id + 1);
	pthread_mutex_unlock(&philo_data->data.log);
	my_usleep(philo_data->data.time_to_sleep * 1000);
}

void	thinking(t_philo *philo_data)
{
	// フォークが空くまでthinkする
	pthread_mutex_lock(&philo_data->data.log);
	print_time_diff(philo_data->data.start_time);
	printf("%d is thinking\n", philo_data->id + 1);
	pthread_mutex_unlock(&philo_data->data.log);
}
