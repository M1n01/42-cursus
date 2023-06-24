/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:28:29 by minabe            #+#    #+#             */
/*   Updated: 2023/06/24 22:00:16 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*philosopher(void *d)
{
	t_philo	*philo_data;

	philo_data = (t_philo *)d;
	if (philo_data->data.num_of_times_each_philo_must_eat == NOT_SET)
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
		while (philo_data->eat_count < philo_data->data.num_of_times_each_philo_must_eat)
		{
			take_forks(philo_data);
			eating(philo_data);
			put_forks(philo_data);
			sleeping(philo_data);
			// フォークが空くまでthinkする
			// thinking(philo_data);
		}
	}
	return (NULL);
}

int	main(int argc, char *argv[])
{
	int			i;
	t_data		*data;
	t_philo		**philo_data;
	pthread_t	*philos;

	if (argc != 5 && argc != 6)
		return (EXIT_FAILURE);
	data = init_data(argc, argv);
	if (data == NULL)
		return (EXIT_FAILURE);
	philos = malloc(sizeof(pthread_t) * data->num_philos);
	if (philos == NULL)
		return (EXIT_FAILURE);
	philo_data = malloc(sizeof(t_philo *) * data->num_philos);
	if (philo_data == NULL)
		return (EXIT_FAILURE);
	philo_data = NULL;
	if (create_philo_threads(data, philos, philo_data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	i = 0;
	while (i < data->num_philos)
	{
		pthread_join(philos[i], NULL);
		free(&philo_data[i]);
		i++;
	}
	destroy_data(data);
	free(philo_data);
	i = 0;
	while (i < data->num_philos)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	// system("leaks -q philo");
	return (0);
}
