/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:25:36 by minabe            #+#    #+#             */
/*   Updated: 2023/07/03 18:31:57 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static bool	check_dead(t_philo *philo_data)
{
	long long time;

	pthread_mutex_lock(&philo_data->shered.mutex);
	time = (get_time_diff(philo_data->shered.start_time) - (philo_data->last_eat_time - philo_data->shered.start_time)) / 1000;
	pthread_mutex_unlock(&philo_data->shered.mutex);
	if (philo_data->shered.time_to_die < time)
		return (true);
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
		pthread_mutex_unlock(&philo_data->shered.mutex);
		if (check_dead(philo_data))
		{
			pthread_mutex_lock(&philo_data->shered.mutex);
			philo_data->is_dead = true;
			pthread_mutex_unlock(&philo_data->shered.mutex);
			return (NULL);
		}
		usleep(100);
	}
}
