/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   which_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 15:41:05 by minabe            #+#    #+#             */
/*   Updated: 2023/07/06 22:48:09 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	first(t_philo *philo_data)
{
	int	right;
	int	left;

	right = philo_data->id;
	left = (philo_data->id + 1) % philo_data->shered->num_of_philos;
	if (philo_data->id % 2 == 0)
		return (right);
	else
		return (left);
}

int	second(t_philo *philo_data)
{
	int	right;
	int	left;

	right = philo_data->id;
	left = (philo_data->id + 1) % philo_data->shered->num_of_philos;
	if (philo_data->id % 2 == 0)
		return (left);
	else
		return (right);
}
