/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 15:41:05 by minabe            #+#    #+#             */
/*   Updated: 2023/06/23 19:29:34 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	first(t_data *data)
{
	int id;

	if (data->id < (data->id + 1) % data->num_philos)
		id = data->id;
	else
		id = (data->id + 1) % data->num_philos;
	return (id);
}

int	second(t_data *data)
{
	int id;

	if (data->id < (data->id + 1) % data->num_philos)
		id = (data->id + 1) % data->num_philos;
	else
		id = data->id;
	return (id);
}
