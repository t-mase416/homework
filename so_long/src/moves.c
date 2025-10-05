// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   moves.c                                            :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: tmase <tmase@student.42tokyo.jp>           +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/08/16 15:27:20 by tmase             #+#    #+#             */
// /*   Updated: 2025/08/18 19:08:59 by tmase            ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

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

void	put_str_to_window(t_game *game)
{
	char	*moves_str;
	char	*display_text;
	moves_str = ft_itoa(game->move_count);
	display_text = ft_strjoin("Moves: ", moves_str);
	mlx_string_put(game->mlx, game->win, 10, 20, 0xFFFFFF, display_text);
	free(moves_str);
	free(display_text);
}

void	move_player(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] == '1')
		return;
	if (game->map[new_y][new_x] == 'C')
		game->coin_count++;
	if (game->map[new_y][new_x] == 'E')
	{
		if (game->coin_count == game->total_coin_amount)
			cleanup_and_exit(game);
		game->player_x = new_x;
		game->player_y = new_y;
		game->move_count++;
		printf("Move count: %d\n", game->move_count);
		draw_map(game);
		return;
	}
	game->map[game->player_y][game->player_x] = '0';
	game->map[new_y][new_x] = 'P';
	game->player_x = new_x;
	game->player_y = new_y;
	game->move_count++;
	printf("Move count: %d\n", game->move_count);
	draw_map(game);
}
