/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 16:20:57 by minabe            #+#    #+#             */
/*   Updated: 2023/06/21 19:22:20 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_philo	*init_data(int argc, char *argv[])
{
	t_philo	*philo;
	int	i;

	philo = malloc(sizeof(t_philo));
	if (philo == NULL)
		return (NULL);
	philo->number_of_philosophers = atoi(argv[1]); // atoiは自作する
	philo->time.time_to_die = atoi(argv[2]);
	philo->time.time_to_eat = atoi(argv[3]);
	philo->time.time_to_sleep = atoi(argv[4]);
	if (argc == 6)
		philo->time.number_of_times_each_philosopher_must_eat = atoi(argv[5]);
	else
		philo->time.number_of_times_each_philosopher_must_eat = -1;
	return (philo);
}

void	destroy_philo(t_philo *philo)
{
	ft_free(philo);
}
