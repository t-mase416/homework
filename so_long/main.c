/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmase <tmase@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:26:18 by tmase             #+#    #+#             */
/*   Updated: 2025/10/06 21:14:55 by tmase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	cleanup(t_game *game)
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
	if (game->clear_flag == 1)
	{
		ft_printf("Congratulation! Game Clear!");
		return (0);
	}
	ft_printf("Game closed\n");
	return (0);
}

static int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		mlx_loop_end(game->mlx);
	if (keycode == KEY_UP)
		event(game, game->player_x, game->player_y - 1);
	if (keycode == KEY_LEFT)
		event(game, game->player_x - 1, game->player_y);
	if (keycode == KEY_DOWN)
		event(game, game->player_x, game->player_y + 1);
	if (keycode == KEY_RIGHT)
		event(game, game->player_x + 1, game->player_y);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (!game_setup(argc, argv, &game))
		return (1);
	if (!window_setup(&game))
		return (1);
	mlx_hook(game.win, 17, 0, mlx_loop_end, game.mlx);
	mlx_hook(game.win, 2, (1L << 0), handle_keypress, &game);
	mlx_loop(game.mlx);
	cleanup(&game);
	get_next_line(-1);
	return (0);
}
