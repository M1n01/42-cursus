/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 15:44:43 by minabe            #+#    #+#             */
/*   Updated: 2023/06/20 16:13:11 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*read_and_join(char *map, int fd, char *buf)
{
	char	*tmp;
	ssize_t	read_size;

	read_size = 1;
	while (read_size != 0)
	{
		ft_bzero(buf, BUFFER_SIZE + 1);
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size < 0)
			ft_error("Failed to read file\n");
		tmp = ft_strjoin(map, buf);
		ft_free(map);
		map = tmp;
	}
	ft_free(buf);
	return (map);
}

char	*get_map(char *file)
{
	int		fd;
	char	*map;
	char	*buf;

	map = ft_strdup("");
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error("Failed to open file");
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		ft_error("Malloc failed");
	map = read_and_join(map, fd, buf);
	close(fd);
	return (map);
}

size_t	count_map_width(char *map)
{
	size_t	i;
	size_t	j;
	size_t	width;

	i = 0;
	width = 0;
	while (map[i] != '\0')
	{
		if (map[i] == '\n')
			i++;
		j = 0;
		while (map[i + j] != '\n' && map[i + j] != '\0')
			j++;
		if (width == 0)
			width = j;
		else if (width != j && j != 0)
			ft_error("Invalid width map.");
		i += j;
	}
	return (width + 1);
}

size_t	count_map_height(char *map)
{
	size_t	i;
	size_t	height;

	i = 0;
	height = 1;
	while (map[i + 1] != '\0')
	{
		if (map[i] == '\n' && map[i + 1] != '\0')
			height++;
		i++;
	}
	return (height);
}
