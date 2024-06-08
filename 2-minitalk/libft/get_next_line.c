/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:20:57 by minabe            #+#    #+#             */
/*   Updated: 2023/02/22 00:09:12 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static char	*gnl_read(char *save, int fd);
static char	*get_line(char *save);
static char	*get_save(char *save);
static void	safer_free(void *p);

char	*get_next_line(int fd)
{
	char		*res;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (save == NULL)
	{
		save = malloc(sizeof(char) * 1);
		if (save == NULL)
			return (NULL);
		save[0] = '\0';
	}
	save = gnl_read(save, fd);
	if (save == NULL)
		return (NULL);
	res = get_line(save);
	save = get_save(save);
	return (res);
}

static char	*gnl_read(char *save, int fd)
{
	ssize_t	rc;
	char	*buf;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	rc = 1;
	while (ft_strchr(save, '\n') == NULL && rc != 0)
	{
		rc = read(fd, buf, BUFFER_SIZE);
		if (rc == -1)
		{
			safer_free(buf);
			safer_free(save);
			return (NULL);
		}
		buf[rc] = '\0';
		save = ft_strjoin(save, buf);
	}
	safer_free(buf);
	return (save);
}

static char	*get_line(char *save)
{
	char	*line;
	char	*find;

	find = ft_strchr(save, '\n');
	if (find == NULL && *save == '\0')
		return (NULL);
	else if (find == NULL && *save != '\0')
	{
		line = malloc(sizeof(char) * (ft_strlen(save) + 1));
		if (line == NULL)
			return (NULL);
		ft_strlcpy(line, save, ft_strlen(save) + 1);
		return (line);
	}
	line = malloc(sizeof(char) * (find - save + 2));
	if (line == NULL)
		return (NULL);
	ft_strlcpy(line, save, find - save + 2);
	return (line);
}

static char	*get_save(char *save)
{
	char	*str;
	char	*find;
	char	*res;
	size_t	len;

	find = ft_strchr(save, '\n');
	if (find == NULL)
	{
		safer_free(save);
		return (NULL);
	}
	str = find + 1;
	len = ft_strlen(str);
	res = malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	ft_strlcpy(res, str, len + 1);
	safer_free(save);
	return (res);
}

static void	safer_free(void *p)
{
	if (p != NULL)
	{
		free(p);
		p = NULL;
	}
}
