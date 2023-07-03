/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:28:29 by minabe            #+#    #+#             */
/*   Updated: 2023/07/03 14:11:54 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*philosopher(void *d)
{
	t_philo		*philo_data;
	pthread_t	tid;

	philo_data = (t_philo *)d;
	pthread_create(&tid, NULL, monitor, philo_data); // philosopherのdeathを監視するスレッド
	pthread_detach(tid);
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
		// while (philo_data->eat_count < philo_data->shered.num_of_times_each_philo_must_eat)
		while (philo_data->shered.is_stop == false)
		{
			if (philo_data->eat_count == philo_data->shered.num_of_times_each_philo_must_eat)
			{
				print_log(philo_data, "died");
				pthread_mutex_lock(&philo_data->shered.mutex);
				philo_data->shered.is_stop = true;
				pthread_mutex_unlock(&philo_data->shered.mutex);
				break ;
			}
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
	// void		*status;

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
		pthread_join(philos[i], NULL); // philo_num == 1のときdetach処理
		// pthread_join(philos[i], &status); // philo_num == 1のときdetach処理
		// if (status != NULL)
		// {
		// 	print_log(philo_data[i], "died");
		// 	break ;
		// }
		i++;
	}
	i = 0;
	while (i < shered->num_philos)
	{
		free(philo_data[i]);
		i++;
	}
	free(philo_data);
	destroy_shered_data(shered);
	// system("leaks -q philo");
	return (0);
}
