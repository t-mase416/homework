/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmase <tmase@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 18:29:14 by tmase             #+#    #+#             */
/*   Updated: 2025/07/25 22:58:58 by tmase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <mlx.h>

# define TILE_SIZE 64
# define KEY_ESC 65307
# define KEY_UP 119
# define KEY_RIGHT 100
# define KEY_LEFT 97
# define KEY_DOWN 115

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_game {
	void	*mlx;
	void	*win;
	void	*wall;
	void	*tile;
	void	*flog;
	void	*coin;
	void	*exit;
	char 	**map;
	int		map_width;
	int		map_height;
}				t_game;

void	destroy_images(t_game *game);
void	draw_tile(t_game *game, char tile_type, int x, int y);
void	draw_map(t_game *game);
void	load_images(t_game *game);

#endif
