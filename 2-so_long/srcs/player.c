/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:23:36 by minabe            #+#    #+#             */
/*   Updated: 2023/06/20 16:31:27 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	read_plr_file(t_game *game);

t_player	init_plr(t_game *game)
{
	t_player	plr;

	read_plr_file(game);
	plr = game->player;
	plr.dir = -1;
	plr.x = -1;
	plr.y = -1;
	plr.pre_x = -1;
	plr.pre_y = -1;
	plr.collects = 0;
	return (plr);
}

static void	read_plr_file(t_game *game)
{
	t_player	*plr;
	int			size;

	size = SIZE;
	plr = &(game->player);
	plr->player_down = mlx_xpm_file_to_image(game->ptr, \
		"./img/sprites/Ghost/ghost_front.xpm", &size, &size);
	if (plr->player_down == NULL)
		ft_error("Cannot main charactor down file");
	plr->player_up = mlx_xpm_file_to_image(game->ptr, \
		"./img/sprites/Ghost/ghost_back.xpm", &size, &size);
	if (plr->player_up == NULL)
		ft_error("Cannot main charactor up file");
	plr->player_right = mlx_xpm_file_to_image(game->ptr, \
		"./img/sprites/Ghost/ghost_right.xpm", &size, &size);
	if (plr->player_right == NULL)
		ft_error("Cannot main charactor right file");
	plr->player_left = mlx_xpm_file_to_image(game->ptr, \
		"./img/sprites/Ghost/ghost_left.xpm", &size, &size);
	if (plr->player_left == NULL)
		ft_error("Cannot main charactor left file");
}

void	destroy_plr(t_game *game)
{
	mlx_destroy_image(game->ptr, game->player.player_down);
	mlx_destroy_image(game->ptr, game->player.player_up);
	mlx_destroy_image(game->ptr, game->player.player_left);
	mlx_destroy_image(game->ptr, game->player.player_right);
}

void	plr_move(t_game *game, int dir)
{
	int		tmp_x;
	int		tmp_y;
	char	*map;

	map = game->map_info.map;
	tmp_x = game->player.x;
	tmp_y = game->player.y;
	if (dir == UP)
		tmp_y -= 1;
	if (dir == DOWN)
		tmp_y += 1;
	if (dir == LEFT)
		tmp_x -= 1;
	if (dir == RIGHT)
		tmp_x += 1;
	if (map[tmp_y * game->map_info.width + tmp_x] != '1')
	{
		game->player.dir = dir;
		game->player.pre_x = game->player.x;
		game->player.pre_y = game->player.y;
		game->player.x = tmp_x;
		game->player.y = tmp_y;
		game->turn++;
		ft_printf("turn: %d\n", (int)game->turn);
	}
}

void	put_plr(t_game *game)
{
	t_player	plr;

	plr = game->player;
	if (plr.dir == DOWN || plr.dir == -1)
		mlx_put_image_to_window(game->ptr, game->win_ptr, \
			plr.player_down, plr.x * 32, plr.y * 32);
	else if (plr.dir == UP)
		mlx_put_image_to_window(game->ptr, game->win_ptr, \
			plr.player_up, plr.x * 32, plr.y * 32);
	else if (plr.dir == LEFT)
		mlx_put_image_to_window(game->ptr, game->win_ptr, \
			plr.player_left, plr.x * 32, plr.y * 32);
	else if (plr.dir == RIGHT)
		mlx_put_image_to_window(game->ptr, game->win_ptr, \
			plr.player_right, plr.x * 32, plr.y * 32);
	if ((plr.pre_x != -1 && plr.pre_y != -1) && \
		game->map_info.map[plr.pre_y * game->map_info.width + plr.pre_x] != 'E')
		mlx_put_image_to_window(game->ptr, game->win_ptr, \
			game->objs.floor, plr.pre_x * 32, plr.pre_y * 32);
}
