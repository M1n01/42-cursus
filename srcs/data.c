/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 16:20:57 by minabe            #+#    #+#             */
/*   Updated: 2023/07/03 09:45:53 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_shered	*init_shered_data(int argc, char *argv[])
{
	int		i;
	t_shered	*shered;

	shered = malloc(sizeof(t_shered));
	if (shered == NULL)
		return (NULL);
	shered->num_philos = my_atoi(argv[1]);
	shered->time_to_die = my_atoi(argv[2]);
	shered->time_to_eat = my_atoi(argv[3]);
	shered->time_to_sleep = my_atoi(argv[4]);
	if (shered->num_philos < 1 || shered->time_to_die < 0 || shered->time_to_eat < 0
		|| shered->time_to_sleep < 0) // philoが1のとき確認
		return (NULL);
	if (argc == 6)
		shered->num_of_times_each_philo_must_eat = atoi(argv[5]);
	else
		shered->num_of_times_each_philo_must_eat = NOT_SET;
	shered->forks = malloc(sizeof(pthread_mutex_t) * shered->num_philos);
	if (shered->forks == NULL)
		return (NULL);
	i = 0;
	while (i < shered->num_philos)
	{
		if (pthread_mutex_init(&shered->forks[i], NULL) != 0)
			return (NULL);
		i++;
	}
	shered->start_time = get_time();
	pthread_mutex_init(&shered->mutex, NULL);
	pthread_mutex_init(&shered->log, NULL);
	return (shered);
}

t_philo	*init_philo_data(t_shered *shered, int id)
{
	t_philo	*philo_data;

	philo_data = malloc(sizeof(t_philo));
	if (philo_data == NULL)
		return (NULL);
	philo_data->id = id;
	philo_data->eat_count = 0;
	philo_data->shered = *shered;
	philo_data->last_eat_time = philo_data->shered.start_time;
	philo_data->is_dead = false;
	return (philo_data);
}

void	destroy_shered_data(t_shered *shered)
{
	int	i;

	i = 0;
	while (i < shered->num_philos)
	{
		pthread_mutex_destroy(&shered->forks[i]);
		i++;
	}
	free(shered->forks);
	pthread_mutex_destroy(&shered->mutex);
	pthread_mutex_destroy(&shered->log);
	free(shered);
}
