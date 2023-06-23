/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 09:38:38 by minabe            #+#    #+#             */
/*   Updated: 2023/06/23 19:54:12 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	take_first_fork(t_data *data)
{
	struct timeval	tv;

	pthread_mutex_lock(&data->forks[first(data)]);
	gettimeofday(&tv, NULL);
	printf("%ld%d ", tv.tv_sec, tv.tv_usec / 1000);
	printf("%d has taken a fork (%d)\n", data->id + 1, first(data) + 1);
}

void	take_second_fork(t_data *data)
{
	struct timeval	tv;

	pthread_mutex_lock(&data->forks[second(data)]);
	gettimeofday(&tv, NULL);
	printf("%ld%d ", tv.tv_sec, tv.tv_usec / 1000);
	printf("%d has taken a fork (%d)\n", data->id + 1, second(data) + 1);
}

void	take_forks(t_data *data)
{
	take_first_fork(data);
	take_second_fork(data);
}

void	put_forks(t_data *data)
{
	pthread_mutex_unlock(&data->forks[first(data)]);
	printf("%d has put a fork (%d)\n", data->id + 1, first(data) + 1);
	pthread_mutex_unlock(&data->forks[second(data)]);
	printf("%d has put a fork (%d)\n", data->id + 1, second(data) + 1);
}

void	eating(t_data *data)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	printf("%ld%d ", tv.tv_sec, tv.tv_usec / 1000);
	printf("%d is eating\n", data->id + 1);
	usleep(data->time.time_to_eat * 1000);
}

void	sleeping(t_data *data)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	printf("%ld%d ", tv.tv_sec, tv.tv_usec / 1000);
	printf("%d is sleeping\n", data->id + 1);
	usleep(data->time.time_to_sleep * 1000);
}

// void	thinking(t_data *philo)
// {
// 	usleep();
// }
