/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 16:20:57 by minabe            #+#    #+#             */
/*   Updated: 2023/07/07 13:29:42 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	input_args(t_shered *shered, int argc, char *argv[])
{
	shered->num_of_philos = my_atoi(argv[1]);
	shered->death_time = my_atoi(argv[2]);
	shered->eat_time = my_atoi(argv[3]);
	shered->sleep_time = my_atoi(argv[4]);
	if (shered->num_of_philos < 1 || shered->death_time < 0
		|| shered->eat_time < 0 || shered->sleep_time < 0)
		return (EXIT_FAILURE);
	if (argc == 6)
	{
		shered->num_of_eat = atoi(argv[5]);
		if (shered->num_of_eat < 1)
			return (EXIT_FAILURE);
	}
	else
		shered->num_of_eat = NOT_SET;
	return (EXIT_SUCCESS);
}

t_shered	*init_shered_data(int argc, char *argv[])
{
	int			i;
	t_shered	*shered;

	shered = malloc(sizeof(t_shered));
	if (shered == NULL)
		return (NULL);
	if (input_args(shered, argc, argv) == EXIT_FAILURE)
		return (NULL);
	shered->forks = malloc(sizeof(pthread_mutex_t) * shered->num_of_philos);
	if (shered->forks == NULL)
		return (NULL);
	i = 0;
	while (i < shered->num_of_philos)
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

t_philo	**init_philo_data(t_shered *shered_data)
{
	t_philo	**philo_data;
	int		i;

	philo_data = malloc(sizeof(t_philo *) * shered_data->num_of_philos);
	if (philo_data == NULL)
		return (NULL);
	i = 0;
	while (i < shered_data->num_of_philos)
	{
		philo_data[i] = malloc(sizeof(t_philo));
		if (philo_data[i] == NULL)
		{
			philo_exit(philo_data, shered_data);
			return (NULL);
		}
		philo_data[i]->shered = shered_data;
		philo_data[i]->id = i;
		philo_data[i]->eat_count = 0;
		philo_data[i]->last_eat_time = shered_data->start_time;
		// philo_data[i]->is_eating = false;
		i++;
	}
	return (philo_data);
}

void	destroy_shered_data(t_shered *shered)
{
	int	i;

	i = 0;
	while (i < shered->num_of_philos)
	{
		pthread_mutex_destroy(&shered->forks[i]);
		i++;
	}
	free(shered->forks);
	pthread_mutex_destroy(&shered->mutex);
	pthread_mutex_destroy(&shered->log);
	free(shered);
}
