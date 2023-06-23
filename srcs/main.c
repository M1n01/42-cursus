/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:28:29 by minabe            #+#    #+#             */
/*   Updated: 2023/06/23 15:59:32 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*philosopher(void *d)
{
	int		i;
	t_data	*data;

	data = (t_data *)d;
	if (data->time.num_of_times_each_philo_must_eat >= 0)
	{
		i = 0;
		while (i < data->time.num_of_times_each_philo_must_eat)
		{
			get_forks(data);
			eating(data);
			put_forks(data);
			sleeping(data);
			// thinking(data);
			i++;
		}
	}
	else
	{
		// while (true)
		// {
		// 	get_forks(data);
		// 	eating(data);
		// 	put_forks(data);
		// 	sleeping(data);
		// 	// thinking(data);
		// }
		printf("4つ目の引数が負の値です\n");
	}
	return (NULL);
}

int	main(int argc, char *argv[])
{
	int		i;
	t_data		*data;
	pthread_t	*philo;

	if (argc != 5 && argc != 6)
		return (1);
	data = init_data(argc, argv);
	philo = malloc(sizeof(pthread_t) * data->num_philos);
	if (philo == NULL)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < data->num_philos)
	{
		data->id = i;
		pthread_create(&philo[i], NULL, philosopher, data);
		i++;
	}
	i = 0;
	while (i < data->num_philos)
	{
		pthread_join(philo[i], NULL);
		i++;
	}
	free(philo);
	destroy_data(data);
	// system("leaks -q philo");
	return (0);
}
