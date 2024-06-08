/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 20:34:14 by minabe            #+#    #+#             */
/*   Updated: 2023/06/20 17:05:38 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static bool	check_objs(t_map *map);
static bool	check_wall(t_map *map);

bool	check_map(t_map *map)
{
	if (!check_objs(map) || !check_wall(map) || !check_reach_objs(map))
	{
		ft_printf("Error\n");
		if (!check_objs(map))
			ft_printf("Invalid map.");
		else if (!check_wall(map))
			ft_printf("Incorrect walls placement.");
		else
			ft_printf("Cannot reach all objects.");
		return (false);
	}
	return (true);
}

static bool	check_objs(t_map *map)
{
	size_t	i;
	size_t	start;
	size_t	goal;

	i = 0;
	start = 0;
	map->items = 0;
	goal = 0;
	while (map->map[i] != '\0')
	{
		if (map->map[i] == 'P')
			start++;
		else if (map->map[i] == 'E')
			goal++;
		else if (map->map[i] == 'C')
			map->items++;
		else if (map->map[i] != '1' && map->map[i] != '0' \
				&& map->map[i] != '\n')
			return (false);
		i++;
	}
	if (start != 1 || goal != 1 || map->items == 0)
		return (false);
	return (true);
}

static bool	check_wall(t_map *map)
{
	size_t	i;

	i = 0;
	while (map->map[i] != '\0')
	{
		if (i < map->width || i > ft_strlen(map->map) - map->width)
		{
			if (map->map[i] != '1' && map->map[i] != '\n')
				return (false);
		}
		if (i % map->width == 0 || i % map->width == map->width - 2)
		{
			if (map->map[i] != '1')
				return (false);
		}
		i++;
	}
	return (true);
}

bool	is_ber_file(char *filename)
{
	char	*ext;

	ext = ft_strrchr(filename, '.');
	if (ft_strcmp(".ber", ext) != 0)
		return (false);
	return (true);
}
