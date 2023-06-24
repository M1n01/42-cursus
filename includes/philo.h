/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:22:47 by minabe            #+#    #+#             */
/*   Updated: 2023/06/24 21:59:02 by minabe           ###   ########.fr       */
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

# define NOT_SET -1

typedef struct s_data
{
	int				num_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_times_each_philo_must_eat;
	pthread_mutex_t	*forks;
}	t_data;

typedef struct s_philo
{
	int				id;
	int				eat_count;
	t_data			data;
}	t_philo;

void		*philosopher(void *d);
int			create_philo_threads(t_data *data, pthread_t *philos, t_philo **philo_data);

t_data		*init_data(int argc, char *argv[]);
t_philo		*philo_data_init(t_data *data, int id);
void		destroy_data(t_data *data);

void		eating(t_philo *philo_data);
void		sleeping(t_philo *philo_data);
void		take_forks(t_philo *philo_data);
void		put_forks(t_philo *philo_data);

int			first(t_philo *philo_data);
int			second(t_philo *philo_data);
long long	get_time(void);
int			my_atoi(const char *str);

#endif