/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 16:20:57 by minabe            #+#    #+#             */
/*   Updated: 2023/06/23 21:26:27 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_data	*init_data(int argc, char *argv[])
{
	int		i;
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (data == NULL)
		return (NULL);
	data->num_philos = atoi(argv[1]); // atoiは自作する
	data->time.time_to_die = atoi(argv[2]);
	data->time.time_to_eat = atoi(argv[3]);
	data->time.time_to_sleep = atoi(argv[4]);
	if (argc == 6)
		data->num_of_times_each_philo_must_eat = atoi(argv[5]);
	else
		data->num_of_times_each_philo_must_eat = -1;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philos); // エラー起きたら確認
	if (data->forks == NULL)
		return (NULL);
	i = 0;
	while (i < data->num_philos)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	data->id = 0;
	data->eat_count = 0;
	return (data);
}

void	destroy_data(t_data *data)
{
	free(data->forks);
	free(data);
}
