/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmase <tmase@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:26:18 by tmase             #+#    #+#             */
/*   Updated: 2025/08/18 19:01:22 by tmase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_player_start(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

int	cleanup_and_exit(t_game *game)
{
	if (game->map)
		free_map(game->map);
	destroy_images(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	printf("Game closed\n");
	exit(0);
	return (0);
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		cleanup_and_exit(game);
	if (keycode == KEY_UP)
		move_up(game);
	if (keycode == KEY_DOWN)
		move_down(game);
	if (keycode == KEY_LEFT)
		move_left(game);
	if (keycode == KEY_RIGHT)
		move_right(game);
	return (0);
}

t_bool	game_setup(int argc, char **argv, t_game *game)
{
	if (argc != 2)
	{
		printf("Error\nargc must be 2");
		return (False);
	}
	*game = (t_game){0};
	game->map = load_map(argv[1]);
	if (!game->map || !check_valid_map(game->map))
	{
		printf("Error\nmap error");
		if (game->map)
			free_map(game->map);
		return (False);
	}
	return (True);
}

t_bool window_setup(t_game *game)
{
	game->mlx = mlx_init();
	game->map_height = get_map_size(game->map);
	game->map_width = ft_strlen(game->map[0]);
	game->win = mlx_new_window(game->mlx, game->map_width * TILE_SIZE,
		game->map_height * TILE_SIZE, "So Long");
	if (!game->win)
	{
		printf("Error: mlx_new_window() failed\n");
		if (game->map)
			free_map(game->map);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		return (False);
	}
	find_player_start(game);
	load_images(game);
	draw_map(game);
	return (True);
}

int main(int argc, char **argv)
{
	t_game game;

	if (!game_setup(argc, argv, &game))
		return (1);
	if (!window_setup(&game))
		return (1);
	mlx_hook(game.win, 17, 0, cleanup_and_exit, &game);
	mlx_hook(game.win, 2, (1L<<0), handle_keypress, &game);
	mlx_loop(game.mlx);
	return (0);
}
