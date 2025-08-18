/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmase <tmase@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 15:27:20 by tmase             #+#    #+#             */
/*   Updated: 2025/08/18 18:22:03 by tmase            ###   ########.fr       */
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

void	move_up(int keycode, t_game *game)
{
	game->map
}

void	move_down(int keycode, t_game *game)
{

}

void	move_left(int keycode, t_game *game)
{

}

void	move_right(int keycode, t_game *game)
{

}
