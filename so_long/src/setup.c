/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmase <tmase@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 19:02:55 by tmase             #+#    #+#             */
/*   Updated: 2025/10/06 19:40:39 by tmase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	memorize_place(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'C')
		game->total_coin_amount++;
	if (game->map[y][x] == 'P')
	{
		game->player_x = x;
		game->player_y = y;
	}
	if (game->map[y][x] == 'E')
	{
		game->exit_x = x;
		game->exit_y = y;
	}
}

static void	check_place(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			memorize_place(game, x, y);
			x++;
		}
		y++;
	}
}

t_bool	game_setup(int argc, char **argv, t_game *game)
{
	if (argc != 2)
	{
		ft_printf("Error\nargs must be 2");
		return (False);
	}
	*game = (t_game){0};
	game->map = load_map(argv[1]);
	if (!game->map || !check_valid_map(game->map))
	{
		ft_printf("Error\nmap error");
		if (game->map)
			free_map(game->map);
		return (False);
	}
	return (True);
}

t_bool	window_setup(t_game *game)
{
	game->mlx = mlx_init();
	game->map_height = get_map_size(game->map);
	game->map_width = ft_strlen(game->map[0]);
	game->win = mlx_new_window(game->mlx, game->map_width * TILE_SIZE,
			game->map_height * TILE_SIZE, "So Long");
	if (!game->win)
	{
		ft_printf("Error: mlx_new_window() failed\n");
		if (game->map)
			free_map(game->map);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		return (False);
	}
	check_place(game);
	load_images(game);
	draw_map(game);
	return (True);
}
