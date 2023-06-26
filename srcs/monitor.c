/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:25:36 by minabe            #+#    #+#             */
/*   Updated: 2023/06/26 17:19:14 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static bool	check_dead(t_philo *philo_data)
{
	long long time;

	time = (get_time_diff(philo_data->data.start_time) / 1000 - (philo_data->last_eat_time - philo_data->data.start_time) / 1000);
	if (philo_data->data.time_to_die < time)
	{
		// printf("%lld\n", time);
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
		pthread_mutex_lock(&philo_data->data.log);
		if (check_dead(philo_data))
		{
			print_time_diff(philo_data->data.start_time);
			printf("%d died\n", philo_data->id + 1);
			philo_data->is_dead = true;
			pthread_mutex_unlock(&philo_data->data.log);
			return (NULL);
		}
		pthread_mutex_unlock(&philo_data->data.log);
	}
}