/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:51:53 by minabe            #+#    #+#             */
/*   Updated: 2023/06/19 15:20:16 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_objs	init_objs(t_game *game)
{
	t_objs	objs;
	int		size;

	size = SIZE;
	objs.wall = mlx_xpm_file_to_image(game->ptr, \
		"./img/sprites/Other/wall.xpm", &size, &size);
	if (objs.wall == NULL)
		ft_error("Cannot read wall file");
	objs.collectible = mlx_xpm_file_to_image(game->ptr, \
		"./img/sprites/Other/item.xpm", &size, &size);
	if (objs.collectible == NULL)
		ft_error("Cannot read collectible file");
	objs.exit = mlx_xpm_file_to_image(game->ptr, \
		"./img/sprites/Other/grave.xpm", &size, &size);
	if (objs.exit == NULL)
		ft_error("Cannot exit wall file");
	objs.floor = mlx_xpm_file_to_image(game->ptr, \
		"./img/sprites/Ghost/black.xpm", &size, &size);
	if (objs.floor == NULL)
		ft_error("Cannot floor wall file");
	return (objs);
}

void	destroy_objs(t_game *game)
{
	mlx_destroy_image(game->ptr, game->objs.wall);
	mlx_destroy_image(game->ptr, game->objs.collectible);
	mlx_destroy_image(game->ptr, game->objs.exit);
	mlx_destroy_image(game->ptr, game->objs.floor);
}

void	put_obj(t_game *game, char c, int x, int y)
{
	if (c == '1')
		mlx_put_image_to_window(game->ptr, game->win_ptr, \
			game->objs.wall, x * SIZE, y * SIZE);
	if (c == 'C' && game->count < game->map_info.items)
	{
		mlx_put_image_to_window(game->ptr, game->win_ptr, \
			game->objs.collectible, x * SIZE, y * SIZE);
		game->items[game->count].x = x;
		game->items[game->count].y = y;
		game->count++;
	}
	else if (c == 'C')
		mlx_put_image_to_window(game->ptr, game->win_ptr, \
			game->objs.collectible, x * SIZE, y * SIZE);
	if (c == 'E')
		mlx_put_image_to_window(game->ptr, game->win_ptr, \
			game->objs.exit, x * SIZE, y * SIZE);
	if (c == '0')
		mlx_put_image_to_window(game->ptr, game->win_ptr, \
			game->objs.floor, x * SIZE, y * SIZE);
	if (c == 'P' && game->player.x == -1 && game->player.y == -1)
	{
		game->player.x = x;
		game->player.y = y;
	}
}
