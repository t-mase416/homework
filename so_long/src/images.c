/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmase <tmase@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 18:57:28 by tmase             #+#    #+#             */
/*   Updated: 2025/10/06 19:40:15 by tmase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	load_images(t_game *game)
{
	int	width;
	int	height;

	game->wall = mlx_xpm_file_to_image(game->mlx,
			"textures/wall.xpm", &width, &height);
	game->tile = mlx_xpm_file_to_image(game->mlx,
			"textures/tile.xpm", &width, &height);
	game->flog = mlx_xpm_file_to_image(game->mlx,
			"textures/flog.xpm", &width, &height);
	game->coin = mlx_xpm_file_to_image(game->mlx,
			"textures/coin.xpm", &width, &height);
	game->exit = mlx_xpm_file_to_image(game->mlx,
			"textures/exit.xpm", &width, &height);
	if (!game->wall || !game->tile || !game->flog || !game->coin || !game->exit)
	{
		ft_printf("Error\nImage loading failed.\n");
		destroy_images(game);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		exit(1);
	}
}

void	destroy_images(t_game *game)
{
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->tile)
		mlx_destroy_image(game->mlx, game->tile);
	if (game->flog)
		mlx_destroy_image(game->mlx, game->flog);
	if (game->coin)
		mlx_destroy_image(game->mlx, game->coin);
	if (game->exit)
		mlx_destroy_image(game->mlx, game->exit);
}
