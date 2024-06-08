/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:20:57 by minabe            #+#    #+#             */
/*   Updated: 2023/06/18 22:12:06 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char	*gnl_read(char *save, int fd);
static char	*get_line(char *save);
static char	*get_save(char *save);

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (save == NULL)
	{
		save = malloc(sizeof(char) * 1);
		if (save == NULL)
			ft_error("Malloc failed");
		save[0] = '\0';
	}
	save = gnl_read(save, fd);
	line = get_line(save);
	save = get_save(save);
	return (line);
}

static char	*gnl_read(char *save, int fd)
{
	ssize_t	read_size;
	char	*buf;
	char	*tmp;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		ft_error("Malloc failed");
	read_size = 1;
	while (ft_strchr(save, '\n') == NULL && read_size != 0)
	{
		ft_bzero(buf, BUFFER_SIZE + 1);
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size == -1)
		{
			ft_free(buf);
			ft_free(save);
			ft_error("Read failed");
		}
		tmp = ft_strjoin(save, buf);
		ft_free(save);
		save = tmp;
	}
	ft_free(buf);
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
			ft_error("Malloc failed");
		ft_strlcpy(line, save, ft_strlen(save) + 1);
		return (line);
	}
	line = malloc(sizeof(char) * (find - save + 1));
	if (line == NULL)
		ft_error("Malloc failed");
	ft_strlcpy(line, save, find - save + 1);
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
		ft_free(save);
		return (NULL);
	}
	str = find + 1;
	len = ft_strlen(str);
	res = malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		ft_error("Malloc failed");
	ft_strlcpy(res, str, len + 1);
	ft_free(save);
	return (res);
}
