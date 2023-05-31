/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 16:20:57 by minabe            #+#    #+#             */
/*   Updated: 2023/05/31 11:17:02 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_philo	*init_philo(int argc, char *argv[])
{
	t_philo	*philo;
	int	i;

	philo = malloc(sizeof(t_philo));
	if (philo == NULL)
		return (NULL);
	philo->number_of_philosophers = atoi(argv[1]); // atoiは自作する
	philo->time_to_die = atoi(argv[2]);
	philo->time_to_eat = atoi(argv[3]);
	philo->time_to_sleep = atoi(argv[4]);
	if (argc == 6)
		philo->number_of_times_each_philosopher_must_eat = atoi(argv[5]);
	else
		philo->number_of_times_each_philosopher_must_eat = -1;
	philo->fork = malloc(sizeof(int) * philo->number_of_philosophers);
	if (philo->fork == NULL)
		return (NULL);
	i = 0;
	while (i < philo->number_of_philosophers)
	{
		philo->fork[i] = true;
		i++;
	}
	pthread_mutex_init(&philo->mutex, NULL);
	return (philo);
}

void	destroy_philo(t_philo *philo)
{
	pthread_mutex_destroy(&philo->mutex);
	free(philo->fork);
	free(philo);
}