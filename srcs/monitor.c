/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:25:36 by minabe            #+#    #+#             */
/*   Updated: 2023/07/09 04:35:21 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static bool	check_dead(t_philo *philo)
{
	long long	time;

	pthread_mutex_lock(&philo->shered->mutex);
	time = (get_time() - philo->last_eat_time) / 1000;
	if (philo->is_eating == false && philo->shered->death_time < time)
	{
		pthread_mutex_unlock(&philo->shered->mutex);
		return (true);
	}
	pthread_mutex_unlock(&philo->shered->mutex);
	return (false);
}

void	*monitor(void *arg)
{
	t_philo		*philo;
	t_shered	*data;

	philo = (t_philo *)arg;
	data = philo->shered;
	pthread_mutex_lock(&data->mutex);
	while (((data->num_of_eat >= 0 && data->num_of_eat > philo->eat_count)
			|| data->num_of_eat == NOT_SET) && data->is_dead == false)
	{
		pthread_mutex_unlock(&data->mutex);
		if (check_dead(philo))
		{
			print_log(philo, "died");
			pthread_mutex_lock(&data->mutex);
			data->is_dead = true;
			pthread_mutex_unlock(&data->mutex);
		}
		pthread_mutex_lock(&data->mutex);
		if (data->num_of_philos == 1)
			usleep(10);
	}
	pthread_mutex_unlock(&data->mutex);
	return (NULL);
}
