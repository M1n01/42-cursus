/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:28:29 by minabe            #+#    #+#             */
/*   Updated: 2023/06/26 12:26:44 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*check_death(void *d)
{
	t_philo	*philo_data;

	philo_data = (t_philo *)d;
	while (true)
	{
		// pthread_mutex_lock(&philo_data->data.log);
		if (get_time_diff(philo_data->data.start_time) - philo_data->last_eat_time > philo_data->data.time_to_die)
		{
			printf("%lld %d died\n", get_time(), philo_data->id + 1);
			// printf("%lld %d died\n", get_time() - philo_data->data.start_time, philo_data->id + 1);
			// philo_data->is_dead = true;
			// pthread_mutex_unlock(&philo_data->data.log);
			return (NULL);
		}
		// pthread_mutex_unlock(&philo_data->data.log);
	}
}

void	*philosopher(void *d)
{
	t_philo		*philo_data;
	pthread_t	tid;

	philo_data = (t_philo *)d;
	pthread_create(&tid, NULL, check_death, philo_data);
	pthread_detach(tid);
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
			thinking(philo_data);
			// フォークが空くまでthinkする
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
	i = 0;
	while (i < data->num_philos)
	{
		philo_data[i] = philo_data_init(data, i);
		if (philo_data == NULL)
			return (EXIT_FAILURE);
		if (pthread_create(&philos[i], NULL, philosopher, philo_data[i]) != 0)
			return (EXIT_FAILURE);
		i++;
	}
	i = 0;
	while (i < data->num_philos)
	{
		pthread_join(philos[i], NULL);
		free(&philo_data[i]);
		i++;
	}
	free(philo_data);
	destroy_data(data);
	// system("leaks -q philo");
	return (0);
}
