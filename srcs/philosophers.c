/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:28:29 by minabe            #+#    #+#             */
/*   Updated: 2023/07/10 08:06:35 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// int	case_one(t_philo *philo)
// {
// 	pthread_t	*philosopher;

// 	philosopher = malloc(sizeof(pthread_t) * shered->num_of_philos);
// 	if (philosopher == NULL)
// 		return (EXIT_FAILURE);
	
// 	return (EXIT_SUCCESS);
// }

int	main(int argc, char *argv[])
{
	t_shered	*shered;
	t_philo		**philo_data;

	if (argc != 5 && argc != 6)
		return (EXIT_FAILURE);
	shered = init_shered_data(argc, argv);
	if (shered == NULL)
		return (EXIT_FAILURE);
	philo_data = init_philo_data(shered);
	if (philo_data == NULL)
	{
		destroy_shered_data(shered);
		return (EXIT_FAILURE);
	}
	// if (shered->num_of_philos == 1)
	// 	return (case_one(philo_data));
	if (thread(philo_data, shered)) // else if
		return (EXIT_FAILURE);
	philo_exit(philo_data, shered);
	return (0);
}
