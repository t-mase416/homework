/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmase <tmase@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 18:29:14 by tmase             #+#    #+#             */
/*   Updated: 2025/07/17 16:58:40 by tmase            ###   ########.fr       */
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
	char 	**map;
	int		map_width;
	int		map_height;
	void	*wall;
	void	*tile;
	void	*flog;
	void	*coin;
	void	*exit;
}				t_game;

void	destroy_images(t_game *game)



#endif
