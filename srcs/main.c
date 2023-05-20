/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:28:29 by minabe            #+#    #+#             */
/*   Updated: 2023/05/20 17:25:35 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	philo(int argc, char *argv[])
{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_each_philosopher_must_eat;

	(void)number_of_times_each_philosopher_must_eat;
	number_of_philosophers = atoi(argv[1]); // atoiは自作する
	time_to_die = atoi(argv[2]);
	time_to_eat = atoi(argv[3]);
	time_to_sleep = atoi(argv[4]);
}

int	main(int argc, char *argv[])
{
	if (argc == 5 || argc == 6)
	{
		philo(argc, argv);
	}
	else
		return (1);
	return (0);
}
