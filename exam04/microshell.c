/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 09:56:16 by minabe            #+#    #+#             */
/*   Updated: 2023/10/03 10:42:31 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

int	err(char *msg)
{
	write(STDERR_FILENO, msg, ft_strlen(msg));
	return (EXIT_FAILURE);
}

int	cd(char **argv, int i)
{
	if (i != 2)
		return (err("error: cd: bad arguments\n"));
	else if (chdir(argv[1]) == -1)
		return (err("error: cd: cannot change directory to "),  err(argv[1]), err("\n"));
	return (EXIT_SUCCESS);
}

int	exec(char **argv, char **envp, int i)
{
	int	status;
	int	fd[2];
	int	has_pipe = argv[i] && !strcmp(argv[i], "|");

	if (has_pipe && pipe(fd) == -1)
		return (err("error: pipe\n"));
	int	pid = fork();
	if (!pid)
	{
		argv[i] = NULL;
		if (has_pipe && dup2(fd[1], STDOUT_FILENO) == -1)
			return (err("error: dup2\n"));
		execve(*argv, argv, envp);
		return (err("error: cannot execute "), err(*argv), err("\n"));
	}
	waitpid(pid, &status, 0);
	if (has_pipe && (dup2(fd[0], STDIN_FILENO) == -1 || close(fd[1]) == -1))
		return (err("error: dup2 or close\n"));
	return (WIFEXITED(status) && WEXITSTATUS(status));
}

int	main(int argc, char **argv, char **envp)
{
	int	i = 0;
	int	status = 0;

	if (argc > 1)
	{
		while (argv[i] && argv[++i])
		{
			argv += i;
			i = 0;
			while (argv[i] && strcmp(argv[i], ";")  && strcmp(argv[i], "|") != 0)
				i++;
			if (!strcmp(*argv, "cd"))
				status = cd(argv, i);
			else if (i)
				status = exec(argv, envp, i);
			i++;
		}
	}
	return (status);
}
