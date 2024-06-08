/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:35:20 by minabe            #+#    #+#             */
/*   Updated: 2023/04/27 16:07:46 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"
#include "../include/libft.h"

static int	g_ack;

static void	send_pid(pid_t server_pid, pid_t client_pid);
static void	send_msg(pid_t my_pid, char *msg);

int	main(int argc, char *argv[])
{
	pid_t	server_pid;
	pid_t	client_pid;

	if (argc != 3)
		ft_error("Usage: ./client [server-pid] [message]");
	server_pid = ft_atoi(argv[1]);
	if (server_pid < 100 || 99998 < server_pid)
		ft_error("Invalid PID. Please enter a number between 100 and 99998.");
	client_pid = getpid();
	send_pid(server_pid, client_pid);
	send_msg(server_pid, argv[2]);
	return (0);
}

void	send_pid(pid_t server_pid, pid_t client_pid)
{
	int	i;
	int	status;

	i = 0;
	while (i < 32)
	{
		usleep(100);
		if (client_pid & (1 << i))
			status = kill(server_pid, SIGUSR1);
		else
			status = kill(server_pid, SIGUSR2);
		if (status == -1)
			ft_error("kill failed\n");
		i++;
	}
}

static void	send_char(pid_t my_pid, char c)
{
	unsigned char	uc;
	size_t			current_bit;
	int				status;

	uc = (unsigned char)c;
	current_bit = 0;
	while (current_bit < 8)
	{
		usleep(100);
		if (uc & (1 << current_bit))
			status = kill(my_pid, SIGUSR1);
		else
			status = kill(my_pid, SIGUSR2);
		if (status == -1)
			ft_error("Invalid PID.");
		current_bit++;
		g_ack = 0;
		while (g_ack != 0)
			pause();
	}
	return ;
}

static void	receive_ack(int signum)
{
	(void)signum;
	g_ack = 1;
	return ;
}

static void	send_msg(pid_t my_pid, char *msg)
{
	size_t				i;
	struct sigaction	s_sa;

	ft_bzero(&s_sa, sizeof(struct sigaction));
	s_sa.sa_handler = receive_ack;
	if (sigaction(SIGUSR1, &s_sa, NULL) == -1)
		ft_error("signal error");
	i = 0;
	while (msg[i] != '\0')
	{
		send_char(my_pid, msg[i]);
		i++;
	}
	send_char(my_pid, EOT);
	return ;
}
