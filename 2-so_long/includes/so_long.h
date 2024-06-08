/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:00:26 by minabe            #+#    #+#             */
/*   Updated: 2023/06/21 15:53:29 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>
# include <unistd.h>
# include <errno.h>
# include <mlx.h>
# include "libft.h"

# define KEY_ESC 53
# define KEY_Q 12
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_UP 126
# define KEY_LEFT 123
# define KEY_DOWN 125
# define KEY_RIGHT 124

# define SIZE 32

enum e_direction
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};

typedef struct s_map
{
	char	*map;
	size_t	width;
	size_t	height;
	int		items;
}	t_map;

typedef struct s_vector
{
	size_t	x;
	size_t	y;
}	t_vector;

typedef struct s_objs
{
	void	*wall;
	void	*exit;
	void	*collectible;
	void	*floor;
}	t_objs;

typedef struct s_player
{
	void	*player_down;
	void	*player_up;
	void	*player_left;
	void	*player_right;
	int		dir;
	int		x;
	int		y;
	int		pre_x;
	int		pre_y;
	int		collects;
}	t_player;

typedef struct s_game
{
	void		*ptr;
	void		*win_ptr;
	int			width;
	int			height;
	t_map		map_info;
	t_objs		objs;
	t_player	player;
	int			count;
	t_vector	*items;
	int			turn;
	bool		clear;
}	t_game;

bool		is_ber_file(char *filename);
size_t		count_map_width(char *map);
size_t		count_map_height(char *map);
bool		check_map(t_map *map);
char		*get_map(char *file);

t_objs		init_objs(t_game *game);
void		destroy_objs(t_game *game);
void		put_obj(t_game *game, char c, int x, int y);

t_player	init_plr(t_game *game);
void		destroy_plr(t_game *game);
void		plr_move(t_game *game, int dir);
void		put_plr(t_game *game);

t_game		*init_game(t_map *mp);
int			print_window(t_game *game);
int			deal_key(int keycode, t_game *game);
int			end_game(t_game *game);

bool		check_reach_objs(t_map *mp);

#endif
