/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmase <tmase@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:26:18 by tmase             #+#    #+#             */
/*   Updated: 2025/07/18 16:40:00 by tmase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include <math.h>
#include "mlx.h"
#include "so_long.h"
#include "map/map.h"

int	close_by_cross(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
	return (0);
}

int	close_by_esc(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
	return (0);
}

int main(int argc, char **argv)
{
	t_game game;

	if (argc != 2)
	{
		printf("Error\nargc must be 2");
		return (1);
	}
	game = (t_game){0};
	game.map = load_map(argv[1]);
	if (!game.map || !check_valid_map(game.map))
	{
		printf("Error\nmap error");
		if (game.map)
			free_map(game.map);
		return (1);
	}
	game.mlx = mlx_init();
	game.map_height = get_map_size(game.map) * TILE_SIZE;
	game.map_width = ft_strlen(game.map[0]) * TILE_SIZE;
	game.win = mlx_new_window(game.mlx, game.map_height, game.map_width, "So Long");
	if (!game.win)
	{
		printf("Error: mlx_new_window() failed\n");
		if (game.map)
			free_map(game.map);
		return (1);
	}
	load_images(&game);
	draw_map(&game);
	mlx_hook(game.win, 17, (1L<<17), close_by_cross, &game);
	mlx_hook(game.win, 2, (1L<<0), close_by_esc, &game);
	mlx_loop(game.mlx);
	return (0);
}
