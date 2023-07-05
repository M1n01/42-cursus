/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 18:35:19 by minabe            #+#    #+#             */
/*   Updated: 2023/07/05 10:29:20 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long long	get_time(void)
{
	struct timeval	tv;
	long long		time;

	gettimeofday(&tv, NULL);
	time = tv.tv_sec * 1000000 + tv.tv_usec;
	return (time);
}

long long	get_time_diff(long long start)
{
	long long	diff;

	diff = get_time() - start;
	return (diff);
}

void	print_time_diff(long long t)
{
	printf("%lld ", get_time_diff(t) / 1000);
}
