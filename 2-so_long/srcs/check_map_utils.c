/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 17:29:56 by minabe            #+#    #+#             */
/*   Updated: 2023/06/19 17:45:26 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static bool	is_valid_move(t_map *map, size_t x, size_t y);
static void	cal_position(t_vector *pos, t_vector *npos, int cmd);
static void	check_obj(t_map *map, t_vector pos, bool *reach, char c);

bool	check_reach_objs(t_map *mp)
{
	t_vector	pos;
	bool		flag;
	char		*map;

	map = mp->map;
	pos.y = 0;
	while (pos.y < mp->height)
	{
		pos.x = 0;
		while (pos.x < mp->width && map[pos.y * mp->width + pos.x] != '\0')
		{
			if (map[pos.y * mp->width + pos.x] == 'C' || \
				map[pos.y * mp->width + pos.x] == 'E')
			{
				flag = false;
				check_obj(mp, pos, &flag, map[pos.y * mp->width + pos.x]);
				if (flag == false)
					return (false);
			}
			pos.x++;
		}
		pos.y++;
	}
	return (true);
}

static bool	is_valid_move(t_map *map, size_t x, size_t y)
{
	if (x < map->width && y < map->height)
	{
		if (map->map[y * map->width + x] != '1')
			return (true);
	}
	return (false);
}

static void	cal_position(t_vector *pos, t_vector *npos, int cmd)
{
	if (cmd == UP || cmd == DOWN)
	{
		npos->x = pos->x;
		if (cmd == UP)
			npos->y = pos->y - 1;
		if (cmd == DOWN)
			npos->y = pos->y + 1;
	}
	else if (cmd == LEFT || cmd == RIGHT)
	{
		if (cmd == LEFT)
			npos->x = pos->x - 1;
		if (cmd == RIGHT)
			npos->x = pos->x + 1;
		npos->y = pos->y;
	}
}

static void	check_obj(t_map *map, t_vector pos, bool *reach, char c)
{
	int			cmd;
	t_vector	cp;

	if (!is_valid_move(map, pos.x, pos.y) || *reach == true)
		return ;
	if (map->map[pos.y * map->width + pos.x] == 'P')
	{
		*reach = true;
		return ;
	}
	c = map->map[pos.y * map->width + pos.x];
	map->map[pos.y * map->width + pos.x] = 'x';
	cmd = -1;
	while (++cmd < 4)
	{
		cal_position(&pos, &cp, cmd);
		if (cp.x < map->width && cp.y < map->height)
		{
			if (map->map[cp.y * map->width + cp.x] != '1' && \
				map->map[cp.y * map->width + cp.x] != 'x')
				check_obj(map, cp, reach, c);
		}
	}
	map->map[pos.y * map->width + pos.x] = c;
	return ;
}
