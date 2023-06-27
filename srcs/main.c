/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:28:29 by minabe            #+#    #+#             */
/*   Updated: 2023/06/27 14:22:31 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*philosopher(void *d)
{
	t_philo		*philo_data;
	// pthread_t	tid;

	philo_data = (t_philo *)d;
	// pthread_create(&tid, NULL, monitor, philo_data);
	// pthread_detach(tid);
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
		while (philo_data->eat_count < philo_data->shered.num_of_times_each_philo_must_eat)
		{
			// pthread_mutex_lock(&philo_data->shered.log);
			// printf("philo[%d] ate last at %lld[ms]\n", philo_data->id + 1, (philo_data->last_eat_time - philo_data->shered.start_time) / 1000);
			// pthread_mutex_unlock(&philo_data->shered.log);
			eating(philo_data);
			sleeping(philo_data);
			thinking(philo_data);
		}
	}
	return (NULL);
}

int	main(int argc, char *argv[])
{
	int			i;
	t_shered	*shered;
	t_philo		**philo_data;
	pthread_t	*philos;

	if (argc != 5 && argc != 6)
		return (EXIT_FAILURE);
	shered = init_shered_data(argc, argv);
	if (shered == NULL)
		return (EXIT_FAILURE);
	philos = malloc(sizeof(pthread_t) * shered->num_philos);
	if (philos == NULL)
		return (EXIT_FAILURE);
	philo_data = malloc(sizeof(t_philo *) * shered->num_philos);
	if (philo_data == NULL)
		return (EXIT_FAILURE);
	i = 0;
	while (i < shered->num_philos)
	{
		philo_data[i] = init_philo_data(shered, i);
		if (philo_data == NULL)
			return (EXIT_FAILURE);
		if (pthread_create(&philos[i], NULL, philosopher, philo_data[i]) != 0)
			return (EXIT_FAILURE);
		i++;
	}
	i = 0;
	while (i < shered->num_philos)
	{
		pthread_join(philos[i], NULL);
		free(&philo_data[i]);
		i++;
	}
	free(philo_data);
	destroy_shered_data(shered);
	// system("leaks -q philo");
	return (0);
}
