/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:25:36 by minabe            #+#    #+#             */
/*   Updated: 2023/07/05 13:02:55 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static bool	check_dead(t_philo *philo_data)
{
	long long	time;

	pthread_mutex_lock(&philo_data->shered.mutex);
	time = (get_time() - philo_data->last_eat_time) / 1000;
	pthread_mutex_unlock(&philo_data->shered.mutex);
	if (philo_data->shered.time_to_die < time)
	{
		printf("[ID: %d, time: %lld, last_eattime: %lld]\n", philo_data->id+1, time, (philo_data->last_eat_time - philo_data->shered.start_time) / 1000);
		return (true);
	}
	return (false);
}

void	*monitor(void *d)
{
	t_philo	*philo_data;

	philo_data = (t_philo *)d;
	while (true)
	{
		pthread_mutex_lock(&philo_data->shered.mutex);
		if (philo_data->shered.is_stop == true)
		{
			pthread_mutex_unlock(&philo_data->shered.mutex);
			return (NULL);
		}
		if (check_dead(philo_data))
		{
			print_log(philo_data, "died");
			pthread_mutex_lock(&philo_data->shered.mutex);
			philo_data->shered.is_stop = true;
			// philo_data->is_dead = true;
			pthread_mutex_unlock(&philo_data->shered.mutex);
			return (NULL);
		}
		pthread_mutex_unlock(&philo_data->shered.mutex);
		usleep(100);
	}
	printf("[monitor]: %d\n", philo_data->id + 1);
	return (NULL);
}
