#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

typedef struct s_client
{
	int id;
	char msg[300000];
} t_client;

t_client clients[1024];
fd_set read_set, write_set, current_set;
int last_fd = 0, g_id = 0;
char send_buffer[300000], recv_buffer[300000];

void error(char *msg)
{
	if (msg)
		write(2, msg, strlen(msg));
	else
		write(2, "Fatal error", 11);
	write(2, "\n", 1);
	exit(1);
}

void send_to_all(int except)
{
	for (int fd = 0; fd <= last_fd; fd++)
	{
		if (FD_ISSET(fd, &write_set) && fd != except)
			if (send(fd, send_buffer, strlen(send_buffer), 0) == -1)
				error(NULL);
	}
}

int main(int ac, char *av[])
{
	if (ac != 2)
		error("Wrong number of arguments");
	int sd = socket(AF_INET, SOCK_STREAM, 0);
	if (sd == -1)
		error(NULL);

	struct sockaddr_in addr;
	socklen_t len;
	bzero(&addr, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(atoi(av[1]));
	addr.sin_addr.s_addr = htonl(INADDR_ANY);

	FD_ZERO(&current_set);
	FD_SET(sd, &current_set);
	bzero(clients, sizeof(clients));
	last_fd = sd;

	if (bind(sd, (const struct sockaddr *)&addr, sizeof(addr)) == -1 || listen(sd, 100) == -1)
		error(NULL);

	while (1)
	{
		read_set = write_set = current_set;
		if (select(last_fd + 1, &read_set, &write_set, NULL, NULL) == -1)
			continue;

		for (int fd = 0; fd <= last_fd; fd++)
		{
			if (FD_ISSET(fd, &read_set))
			{
				if (fd == sd)
				{
					int new_fd = accept(sd, (struct sockaddr *)&addr, &len);
					if (new_fd == -1)
						continue;
					if (new_fd > last_fd)
						last_fd = new_fd;
					clients[new_fd].id = g_id++;
					FD_SET(new_fd, &current_set);
					sprintf(send_buffer, "server: client %d just arrived\n", g_id);
					send_to_all(new_fd);
				}
				else
				{
					int ret = recv(fd, recv_buffer, strlen(recv_buffer), 0);
					if (ret <= 0)
					{
						sprintf(send_buffer, "server: client %d just left\n", clients[fd].id);
						send_to_all(fd);
						FD_CLR(fd, &current_set);
						close(fd);
						bzero(clients[fd].msg, strlen(clients[fd].msg));
					}
					else
					{
						for (int i = 0, j = strlen(clients[fd].msg); i < ret; i++, j++)
						{
							clients[fd].msg[j] = recv_buffer[i];
							if (clients[fd].msg[j] == '\n')
							{
								clients[fd].msg[j] = '\0';
								sprintf(send_buffer, "client %d: %s\n", clients[fd].id, clients[fd].msg);
								send_to_all(fd);
								bzero(clients[fd].msg, strlen(clients[fd].msg));
								j = -1;
							}
						}
					}
				}
				break;
			}
		}
	}
	return (0);
}
