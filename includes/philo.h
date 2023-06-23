/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:22:47 by minabe            #+#    #+#             */
/*   Updated: 2023/06/23 21:25:30 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdbool.h>

typedef struct s_time
{
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
}	t_time;

typedef struct s_data
{
	int				id;
	int				eat_count;
	int				num_philos;
	int				num_of_times_each_philo_must_eat;
	t_time			time;
	pthread_mutex_t	*forks;
}	t_data;

t_data	*init_data(int argc, char *argv[]);
void	destroy_data(t_data *data);

void	eating(t_data *data);
void	sleeping(t_data *data);
void	take_forks(t_data *data);
void	put_forks(t_data *data);

int	first(t_data *data);
int	second(t_data *data);

#endif