/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:01:11 by minabe            #+#    #+#             */
/*   Updated: 2023/07/07 00:43:49 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	*philo_routine(void *arg)
{
	t_philo		*philo;
	pthread_t	tid;

	philo = (t_philo *)arg;
	pthread_create(&tid, NULL, monitor, philo);
	pthread_detach(tid);
	if (philo->shered->num_of_eat == NOT_SET)
	{
		while (philo->shered->is_dead == false)
		{
			eating(philo);
			sleeping(philo);
			thinking(philo);
		}
	}
	else
	{
		while (philo->eat_count < philo->shered->num_of_eat && !philo->shered->is_dead)
		{
			eating(philo);
			sleeping(philo);
			thinking(philo);
		}
	}
	return (NULL);
}

static int	take_their_seat(t_philo **philo_data, t_shered *shered, pthread_t *philo)
{
	int	i;

	i = 0;
	while (i < shered->num_of_philos)
	{
		if (philo_data[i] == NULL)
		{
			free(philo);
			philo_exit(philo_data, shered);
			return (EXIT_FAILURE);
		}
		if (pthread_create(&philo[i], NULL, philo_routine, philo_data[i]))
		{
			free(philo);
			philo_exit(philo_data, shered);
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

static int	start_dinner(t_shered *shered, pthread_t *philosopher)
{
	int	i;

	if (shered->num_of_philos == 1)
	{
		if (pthread_detach(philosopher[0])) // できていない
			return (EXIT_FAILURE);
	}
	else
	{
		i = 0;
		while (i < shered->num_of_philos)
		{
			if (pthread_join(philosopher[i], NULL))
				return (EXIT_FAILURE);
			i++;
		}
	}
	return (EXIT_SUCCESS);
}

int	thread(t_philo **philo_data, t_shered *shered)
{
	pthread_t	*philosopher;

	philosopher = malloc(sizeof(pthread_t) * shered->num_of_philos);
	if (philosopher == NULL)
		return (EXIT_FAILURE);
	if (take_their_seat(philo_data, shered, philosopher))
		return (EXIT_FAILURE);
	if (start_dinner(shered, philosopher) == EXIT_FAILURE)
	{
		if (shered->is_dead == true)
			printf("hello\n");
		philo_error(philo_data, shered);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
