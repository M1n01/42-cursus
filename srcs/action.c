/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 09:38:38 by minabe            #+#    #+#             */
/*   Updated: 2023/06/24 18:29:28 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	take_forks(t_philo *philo_data)
{
	pthread_mutex_lock(&philo_data->data.forks[first(philo_data)]);
	printf("%lld ", get_time());
	printf("%d has taken a fork (%d)\n", philo_data->id + 1, first(philo_data) + 1);
	pthread_mutex_lock(&philo_data->data.forks[second(philo_data)]);
	printf("%lld ", get_time());
	printf("%d has taken a fork (%d)\n", philo_data->id + 1, second(philo_data) + 1);
}

void	put_forks(t_philo *philo_data)
{
	pthread_mutex_unlock(&philo_data->data.forks[first(philo_data)]);
	// printf("%d has put a fork (%d)\n", philo_data->id + 1, first(philo_data) + 1);
	pthread_mutex_unlock(&philo_data->data.forks[second(philo_data)]);
	// printf("%d has put a fork (%d)\n", philo_data->id + 1, second(philo_data) + 1);
}

void	eating(t_philo *philo_data)
{
	printf("%lld ", get_time());
	printf("%d is eating\n", philo_data->id + 1);
	philo_data->eat_count++;
	// printf("id: %d, eat_count: %d\n", philo_data->id + 1, philo_data->eat_count);
	usleep(philo_data->data.time_to_eat * 1000);
}

void	sleeping(t_philo *philo_data)
{
	printf("%lld ", get_time());
	printf("%d is sleeping\n", philo_data->id + 1);
	usleep(philo_data->data.time_to_sleep * 1000);
}

// void	thinking(t_philo *philo_philo)
// {
// 	usleep();
// }
