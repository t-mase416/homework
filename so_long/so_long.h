/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmase <tmase@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 18:29:14 by tmase             #+#    #+#             */
/*   Updated: 2025/10/06 21:01:09 by tmase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "minilibx-linux/mlx.h"
# include "map/map.h"

# define TILE_SIZE 64
# define KEY_ESC 65307
# define KEY_UP 119
# define KEY_RIGHT 100
# define KEY_LEFT 97
# define KEY_DOWN 115

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*wall;
	void	*tile;
	void	*flog;
	void	*coin;
	void	*exit;
	char	**map;
	int		map_width;
	int		map_height;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		total_coin_amount;
	int		coin_count;
	int		clear_flag;
}				t_game;

t_bool	window_setup(t_game *game);
t_bool	game_setup(int argc, char **argv, t_game *game);
void	destroy_images(t_game *game);
void	draw_tile(t_game *game, char tile_type, int x, int y);
void	draw_map(t_game *game);
void	load_images(t_game *game);
void	event(t_game *game, int new_x, int new_y);
int		cleanup(t_game *game);

#endif
