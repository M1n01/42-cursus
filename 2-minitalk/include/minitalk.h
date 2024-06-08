/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:28:54 by minabe            #+#    #+#             */
/*   Updated: 2023/04/27 12:35:27 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <signal.h>
# include <sys/types.h>
# include <stdlib.h>
# include <sysexits.h>
# include <stdbool.h>
# include "../../0-libft/libft.h"
# include "../../1-printf/include/ft_printf.h"
# define EOT 4

typedef struct s_server
{
	int		current_bit;
	int		binary;
	pid_t	client_pid;
}				t_server;

void	receive_pid(void);
void	receive_msg(void);

#endif
