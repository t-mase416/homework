/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmase <tmase@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 19:14:11 by tmase             #+#    #+#             */
/*   Updated: 2025/08/18 18:59:11 by tmase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_tile(t_game *game, char tile_type, int x, int y)
{
	void	*image_to_draw;
	int		width;
	int		height;

	if (tile_type == '1')
		image_to_draw = game->wall;
	else if (tile_type == 'P')
		image_to_draw = game->flog;
	else if (tile_type == 'C')
		image_to_draw = game->coin;
	else if (tile_type == 'E')
		image_to_draw = game->exit;
	else
		return ;
	width = x * TILE_SIZE;
	height = y * TILE_SIZE;
	mlx_put_image_to_window(game->mlx, game->win,
		image_to_draw, width, height);
}

void	draw_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			mlx_put_image_to_window(game->mlx, game->win, game->tile,
				x * TILE_SIZE, y * TILE_SIZE);
			draw_tile(game, game->map[y][x], x, y);
			x++;
		}
		y++;
	}
}
