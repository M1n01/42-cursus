/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:22:47 by minabe            #+#    #+#             */
/*   Updated: 2023/06/27 12:11:30 by minabe           ###   ########.fr       */
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

typedef struct s_shered
{
	int				num_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_times_each_philo_must_eat;
	long long		start_time;
	bool			is_stop;
	pthread_mutex_t	*forks;
	pthread_mutex_t	log; // mutexに変更する
}	t_shered;

typedef struct s_philo
{
	int			id;
	int			eat_count;
	long long	last_eat_time;
	bool		is_dead;
	t_shered	shered;
}	t_philo;

void		*philosopher(void *d);
void		*monitor(void *d);

t_shered	*init_shered_data(int argc, char *argv[]);
t_philo		*init_philo_data(t_shered *shered, int id);
void		destroy_data(t_shered *shered);

void		eating(t_philo *philo_data);
void		sleeping(t_philo *philo_data);
void		take_forks(t_philo *philo_data);
void		put_forks(t_philo *philo_data);
void		thinking(t_philo *philo_data);

int			first(t_philo *philo_data);
int			second(t_philo *philo_data);
long long	get_time(void);
long long	get_time_diff(long long time);
void		print_time_diff(long long time);
int			my_atoi(const char *str);
void		my_usleep(long long action_time);
void	print_log(t_philo *philo_data, char *str, pthread_mutex_t mutex);

#endif