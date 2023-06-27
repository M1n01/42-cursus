/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 18:37:03 by minabe            #+#    #+#             */
/*   Updated: 2023/06/27 11:55:56 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_log(t_philo *philo_data, char *str, pthread_mutex_t mutex)
{
	// pthread_mutex_lock(&philo_data->shered.log);
	// if (philo_data->is_dead == true)
	// {
	// 	pthread_mutex_unlock(&philo_data->shered.log);
	// 	return ;
	// }
	// pthread_mutex_unlock(&philo_data->shered.log);
	pthread_mutex_lock(&mutex);
	print_time_diff(philo_data->shered.start_time);
	printf("%d ", philo_data->id + 1);
	printf("%s\n", str);
	pthread_mutex_unlock(&mutex);
	return ;
}
