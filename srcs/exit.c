/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:01:09 by minabe            #+#    #+#             */
/*   Updated: 2023/07/03 17:34:15 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	philo_exit(t_philo **philo_data)
{
	int			i;
	int			n;
	t_shered	*shered;

	i = 0;
	n = philo_data[0]->shered.num_philos;
	shered = &philo_data[0]->shered;
	while (i < n)
	{
		free(&philo_data[i]);
		i++;
	}
	free(philo_data);
	destroy_shered_data(shered);
}
