/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:28:29 by minabe            #+#    #+#             */
/*   Updated: 2023/06/03 15:23:17 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*philo_eat(void *data)
{
	t_philo	*philo;
	struct timeval tv;

	philo = (t_philo *)data;
	pthread_mutex_lock(&philo->mutex);
	gettimeofday(&tv, NULL);
	philo->fork[philo->right] = false;
	printf("%ld%d ", tv.tv_sec, tv.tv_usec / 1000);
	printf("%d has taken a fork\n", philo->right + 1);
	philo->fork[philo->left] = false;
	printf("%ld%d ", tv.tv_sec, tv.tv_usec / 1000);
	printf("%d has taken a fork\n", philo->right + 1);
	printf("%ld%d ", tv.tv_sec, tv.tv_usec / 1000);
	printf("%d is eating\n", philo->right + 1);
	pthread_mutex_unlock(&philo->mutex);
	usleep(philo->time_to_eat * 1000);
	printf("%ld%d ", tv.tv_sec, tv.tv_usec / 1000);
	printf("finish eating\n");
	return (NULL);
}

void	*philo_sleep(void *data)
{
	t_philo	*philo;
	struct timeval tv;

	philo = (t_philo *)data;
	pthread_mutex_lock(&philo->mutex);
	gettimeofday(&tv, NULL);
	printf("%ld%d ", tv.tv_sec, tv.tv_usec / 1000);
	printf("%d is sleeping\n", philo->right + 1);
	usleep(philo->time_to_sleep * 1000);
	pthread_mutex_unlock(&philo->mutex);
	return (NULL);
}

void	philo(int argc, char *argv[])
{
	int	i;
	bool	*forks;
	t_philo	*philo;
	pthread_t	*tid;
	struct timeval tv;

	philo = init_philo(argc, argv);
	printf("philos: %d\n", philo->number_of_philosophers);
	printf("die time: %d\n", philo->time_to_die);
	printf("eat time: %d\n", philo->time_to_eat);
	printf("sleep time: %d\n", philo->time_to_sleep);
	tid = malloc(sizeof(pthread_t) * 4);
	if (tid == NULL)
		return ;

	gettimeofday(&tv, NULL);
	forks = philo->fork;
	i = 0;
	while (i < philo->number_of_philosophers)
	{
		philo->right = i;
		philo->left = (i + 1) % philo->number_of_philosophers;
		if (forks[philo->right] == true && forks[philo->left] == true)
		{
			pthread_create(&tid[i], NULL, philo_eat, philo);
		}
		else
		{
			pthread_create(&tid[i], NULL, philo_sleep, philo);
		}
		// pthread_join(tid[i], NULL);
		i++;
	}
	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);
	pthread_join(tid[2], NULL);
	pthread_join(tid[3], NULL);
	i = 0;
	while (i < philo->number_of_philosophers)
	{
		printf("%d\n", philo->fork[i]);
		// pthread_join(tid[i], NULL);
		i++;
	}
	// pthread_create(&tid[2], NULL, think, philo);
	// pthread_join(tid[2], NULL);

	destroy_philo(philo);
	free(tid);
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
