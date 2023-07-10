/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:01:09 by minabe            #+#    #+#             */
/*   Updated: 2023/07/10 09:15:13 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	philo_exit(t_philo **philo_data, t_shered *shered)
{
	int	i;
	int	n;

	i = 0;
	n = shered->num_of_philos;
	if (n == 1)
		return ;
	while (i < n && philo_data[i] != NULL)
	{
		free(philo_data[i]);
		i++;
	}
	free(philo_data);
	destroy_shered_data(shered);
}
