/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 21:35:19 by minabe            #+#    #+#             */
/*   Updated: 2023/06/24 21:54:46 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	create_philo_threads(t_data *data, pthread_t *philos, t_philo **philo_data)
{
	int			i;
	t_philo		**philo_data;

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
	return (EXIT_SUCCESS);
}