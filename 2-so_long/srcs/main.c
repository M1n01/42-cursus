/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:43:24 by minabe            #+#    #+#             */
/*   Updated: 2023/06/20 17:06:04 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	so_long(char *file);
static void	start_game(t_map *map);

int	main(int argc, char **argv)
{
	if (argc < 2)
		ft_error("No map file.");
	if (!is_ber_file(argv[1]))
		ft_error("Not a .ber file.");
	so_long(argv[1]);
	return (0);
}

static void	so_long(char *file)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (map == NULL)
		ft_error("Malloc failed.");
	map->map = get_map(file);
	map->width = count_map_width(map->map);
	map->height = count_map_height(map->map);
	if (!check_map(map))
	{
		ft_free(map);
		exit(1);
	}
	start_game(map);
	return ;
}

static void	start_game(t_map *map)
{
	t_game	*game;

	game = init_game(map);
	game->win_ptr = mlx_new_window(game->ptr, \
		game->width, game->height, "so_long");
	if (game->win_ptr == NULL)
		ft_error("Mlx window init failed");
	mlx_loop_hook(game->ptr, print_window, game);
	mlx_key_hook(game->win_ptr, deal_key, game);
	mlx_hook(game->win_ptr, 17, 0, end_game, game);
	ft_printf("Game start!!\n");
	ft_printf("Pick up items and make the ghost come to life in his grave!\n");
	mlx_loop(game->ptr);
	return ;
}
