/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:01:11 by minabe            #+#    #+#             */
/*   Updated: 2023/07/05 10:31:11 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	*philo_routine(void *d)
{
	t_philo		*philo_data;
	// pthread_t	tid;

	philo_data = (t_philo *)d;
	// pthread_create(&tid, NULL, monitor, philo_data); // philosopherのdeathを監視するスレッド
	// pthread_detach(tid);
	// 誰かが死んだらその時点で終了する
	if (philo_data->shered.num_of_times_each_philo_must_eat == NOT_SET)
	{
		// while (true)
		// {
		// 	get_forks(data);
		// 	eating(data);
		// 	put_forks(data);
		// 	sleeping(data);
		// 	// thinking(data);
		// }
		printf("4つ目の引数を入れてください\n");
	}
	else
	{
		pthread_mutex_lock(&philo_data->shered.mutex);
		while (philo_data->eat_count < philo_data->shered.num_of_times_each_philo_must_eat && philo_data->shered.is_stop == false)
		{
			// if (philo_data->shered.is_stop == true)
			// {
			// 	printf("[is_stop]\n");
			// 	break ;
			// }
			// if (philo_data->is_dead == true)
			// {
			// 	printf("[is_dead]: ");
			// 	printf("%d\n", philo_data->id+1);
			// 	pthread_mutex_lock(&philo_data->shered.mutex);
			// 	philo_data->shered.is_stop = true;
			// 	pthread_mutex_unlock(&philo_data->shered.mutex);
			// 	break ;
			// }
			pthread_mutex_unlock(&philo_data->shered.mutex);
			eating(philo_data);
			sleeping(philo_data);
			thinking(philo_data);
			pthread_mutex_lock(&philo_data->shered.mutex);
		}
		pthread_mutex_unlock(&philo_data->shered.mutex);
	}
	return (NULL);
}

static int	start_dinner(t_shered *shered, pthread_t *philosopher)
{
	int	i;

	if (shered->num_philos == 1)
	{
		if (pthread_detach(philosopher[0]))
			return (EXIT_FAILURE);
	}
	else
	{
		i = 0;
		while (i < shered->num_philos)
		{
			if (pthread_join(philosopher[i], NULL))
				return (EXIT_FAILURE);
			i++;
		}
	}
	return (EXIT_SUCCESS);
}

static int	take_their_seat(t_philo **philo_data, t_shered *shered, pthread_t *philo)
{
	int			i;

	i = 0;
	while (i < shered->num_philos)
	{
		philo_data[i] = init_philo_data(shered, i);
		if (philo_data[i] == NULL)
		{
			while (i > 0)
				free(philo_data[--i]);
			free(philo);
			destroy_shered_data(shered);
			return (EXIT_FAILURE);
		}
		if (pthread_create(&philo[i], NULL, philo_routine, philo_data[i]))
		{
			while (i > 0)
				free(philo_data[--i]);
			free(philo);
			destroy_shered_data(shered);
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	thread(t_philo **philo_data, t_shered *shered)
{
	pthread_t	*philosopher;

	philosopher = malloc(sizeof(pthread_t) * shered->num_philos);
	if (philosopher == NULL)
	{
		destroy_shered_data(shered);
		return (EXIT_FAILURE);
	}
	if (take_their_seat(philo_data, shered, philosopher))
	{
		free(philo_data);
		return (EXIT_FAILURE);
	}
	if (start_dinner(shered, philosopher) == EXIT_FAILURE)
	{
		philo_error(philo_data);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
