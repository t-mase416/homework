/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmase <tmase@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 15:27:20 by tmase             #+#    #+#             */
/*   Updated: 2025/08/18 19:08:59 by tmase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_maps(char **map)
{
	int y = 0;

	while (map[y])
	{
		printf("%s\n", map[y]);
		y++;
	}
}

void	move_up(t_game *game)
{
	int	x;
	int	y;

	if (game->map)
	x = game->player_x;
	y = game->player_y;
	game->map[x][y] = game->map[x][y - 1];
	game->map[x][y - 1] = 'P';
	draw_map(game);
	print_maps(game->map);
}

void	move_down(t_game *game)
{
	int	x;
	int	y;

	if (game->map)
	x = game->player_x;
	y = game->player_y;
	game->map[x][y] = game->map[x][y + 1];
	game->map[x][y + 1] = 'P';
	draw_map(game);
	print_maps(game->map);
}

void	move_left(t_game *game)
{
	int	x;
	int	y;

	if (game->map)
	x = game->player_x;
	y = game->player_y;
	game->map[x][y] = game->map[x - 1][y];
	game->map[x - 1][y] = 'P';
	draw_map(game);
	print_maps(game->map);
}

void	move_right(t_game *game)
{
	int	x;
	int	y;

	if (game->map)
	x = game->player_x;
	y = game->player_y;
	game->map[x][y] = game->map[x + 1][y];
	game->map[x + 1][y] = 'P';
	draw_map(game);
	print_maps(game->map);
}
