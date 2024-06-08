/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:31:39 by minabe            #+#    #+#             */
/*   Updated: 2023/06/19 17:48:17 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	check_game(t_game *game);

t_game	*init_game(t_map *mp)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (game == NULL)
		ft_error("Malloc failed.");
	game->ptr = mlx_init();
	if (game->ptr == NULL)
		ft_error("Mlx init failed.");
	game->win_ptr = NULL;
	game->width = (mp->width - 1) * SIZE;
	game->height = mp->height * SIZE;
	game->map_info.map = mp->map;
	game->map_info.width = mp->width;
	game->map_info.height = mp->height;
	game->map_info.items = mp->items;
	game->objs = init_objs(game);
	game->player = init_plr(game);
	game->count = 0;
	game->items = malloc(sizeof(t_vector) * mp->items);
	if (game->items == NULL)
		ft_error("Malloc failed.");
	game->turn = 0;
	game->clear = false;
	return (game);
}

int	print_window(t_game *game)
{
	size_t	i;
	size_t	j;
	size_t	width;
	size_t	height;
	char	*map;

	map = game->map_info.map;
	width = game->map_info.width;
	height = game->map_info.height;
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width && map[i * width + j] != '\0')
		{
			put_obj(game, map[i * width + j], j, i);
			j++;
		}
		i++;
	}
	check_game(game);
	return (0);
}

static int	check_game(t_game *game)
{
	put_plr(game);
	if (game->map_info.map[game->player.y * game->map_info.width + \
		game->player.x] == 'C')
	{
		game->player.collects++;
		game->map_info.map[game->player.y * game->map_info.width + \
			game->player.x] = '0';
	}
	if (game->map_info.map[game->player.y * game->map_info.width + \
		game->player.x] == 'E' && game->player.collects == game->map_info.items)
	{
		game->clear = true;
		end_game(game);
	}
	return (0);
}

int	deal_key(int keycode, t_game *game)
{
	if (keycode == KEY_Q || keycode == KEY_ESC)
		end_game(game);
	if (keycode == KEY_W || keycode == KEY_UP)
		plr_move(game, UP);
	if (keycode == KEY_A || keycode == KEY_LEFT)
		plr_move(game, LEFT);
	if (keycode == KEY_S || keycode == KEY_DOWN)
		plr_move(game, DOWN);
	if (keycode == KEY_D || keycode == KEY_RIGHT)
		plr_move(game, RIGHT);
	check_game(game);
	return (0);
}

int	end_game(t_game *game)
{
	if (game->clear == false)
		ft_printf("Exit game.\n");
	else
		ft_printf("Congrats!! Game Clear!!\n");
	mlx_destroy_window(game->ptr, game->win_ptr);
	destroy_plr(game);
	destroy_objs(game);
	ft_free(game->map_info.map);
	ft_free(game->items);
	ft_free(game);
	exit(0);
	return (0);
}
