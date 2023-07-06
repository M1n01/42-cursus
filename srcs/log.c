/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 18:37:03 by minabe            #+#    #+#             */
/*   Updated: 2023/07/07 00:20:32 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	print_log(t_philo *philo_data, char *str)
{
	long long	time;

	time = get_time_diff(philo_data->shered->start_time) / 1000;
	pthread_mutex_lock(&philo_data->shered->mutex);
	if (philo_data->shered->is_dead == 0)
		printf("%lld %d %s\n", time, philo_data->id + 1, str);
	pthread_mutex_unlock(&philo_data->shered->mutex);
	return (0);
}
