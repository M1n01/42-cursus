/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:28:29 by minabe            #+#    #+#             */
/*   Updated: 2023/06/21 20:02:30 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	philosopher(void *data)
{
	t_philo	*philo;
	struct timeval tv;

	philo = (t_philo *)data;
	gettimeofday(&tv, NULL);
	eating(philo);
	sleeping(philo);
	thinking(philo);
}

int	main(int argc, char *argv[])
{
	size_t	i;
	t_philo		*data;
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
		pthread_create(philo[i], NULL, philosopher, data);
		i++;
	}
	i = 0;
	while (i < data->num_philos)
	{
		pthread_join(philo[i], NULL);
		i++;
	}
	ft_free(philo);
	destroy_philo(data);
	// system("leaks -q philo");
	return (0);
}
