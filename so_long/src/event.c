/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmase <tmase@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 19:22:12 by tmase             #+#    #+#             */
/*   Updated: 2025/10/06 20:56:25 by tmase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	move_player(t_game *game, int new_x, int new_y)
{
	static int	move_count = 0;

	game->map[game->player_y][game->player_x] = '0';
	game->map[new_y][new_x] = 'P';
	game->player_x = new_x;
	game->player_y = new_y;
	move_count++;
	ft_printf("Move count: %d\n", move_count);
	draw_map(game);
}

void	event(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] == '1')
		return ;
	if (game->map[new_y][new_x] == 'C')
	{
		game->coin_count++;
		if (game->coin_count == game->total_coin_amount)
			game->map[game->exit_y][game->exit_x] = 'E';
	}
	if (game->map[new_y][new_x] == 'E')
	{
		if (game->coin_count == game->total_coin_amount)
		{
			game->clear_flag = 1;
			mlx_loop_end(game->mlx);
		}
	}
	move_player(game, new_x, new_y);
}
