/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:28:29 by minabe            #+#    #+#             */
/*   Updated: 2023/05/31 22:36:06 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*fork_dead(void *data)
{
	// int	i;
	bool	*forks;
	t_philo	*philo;

	philo = (t_philo *)data;
	forks = philo->fork;
	pthread_mutex_lock(&philo->mutex);
	// i = 0;
	// while (i < philo->number_of_philosophers)
	// {
	// 	pthread_mutex_lock(&philo->mutex);
	// 	forks[i] = false;
	// 	pthread_mutex_unlock(&philo->mutex);
	// 	i++;
	// }
	forks[philo->number_of_philosophers - 1] = false;
	pthread_mutex_unlock(&philo->mutex);
	return (NULL);
}

void	philo(int argc, char *argv[])
{
	t_philo	*philo;
	pthread_t	tid;
	// struct timeval tv;

	philo = init_philo(argc, argv);
	printf("philos: %d\n", philo->number_of_philosophers);
	printf("die time: %d\n", philo->time_to_die);
	printf("eat time: %d\n", philo->time_to_eat);
	printf("sleep time: %d\n", philo->time_to_sleep);

	pthread_create(&tid, NULL, fork_dead, philo);
	pthread_join(tid, NULL); // 同期処理
	printf("forks: %d\n", philo->fork[philo->number_of_philosophers - 1]);
	// while (true)
	// {
	// 	gettimeofday(&tv, NULL);
	// 	printf("%ld\n", tv.tv_sec);
	// 	printf("%d\n", tv.tv_usec);
	// }
	destroy_philo(philo);
}

int	main(int argc, char *argv[])
{
	if (argc == 5 || argc == 6)
	{
		philo(argc, argv);
	}
	else
		return (1);
	// system("leaks -q philo");
	return (0);
}
