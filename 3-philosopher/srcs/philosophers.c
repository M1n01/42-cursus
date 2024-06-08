/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:28:29 by minabe            #+#    #+#             */
/*   Updated: 2023/07/10 09:49:54 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char *argv[])
{
	t_shered	*shered;
	t_philo		**philo_data;

	if (argc != 5 && argc != 6)
		return (EXIT_FAILURE);
	shered = init_shered_data(argc, argv);
	if (shered == NULL)
		return (EXIT_FAILURE);
	philo_data = init_philo_data(shered);
	if (philo_data == NULL)
	{
		destroy_shered_data(shered);
		return (EXIT_FAILURE);
	}
	if (thread(philo_data, shered))
		return (EXIT_FAILURE);
	philo_success(philo_data, shered);
	return (0);
}
