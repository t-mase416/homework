/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmase <tmase@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 18:57:28 by tmase             #+#    #+#             */
/*   Updated: 2025/07/17 16:59:42 by tmase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	load_images(t_game *game)
{
	int	width;
	int	height;

	game->wall = mlx_xpm_file_to_image(game->mlx, "wall.xpm", &width, &height);
	game->tile = mlx_xpm_file_to_image(game->mlx, "tile.xpm", &width, &height);
	game->flog = mlx_xpm_file_to_image(game->mlx, "flog.xpm", &width, &height);
	game->coin = mlx_xpm_file_to_image(game->mlx, "coin.xpm", &width, &height);
	game->exit = mlx_xpm_file_to_image(game->mlx, "exit.xpm", &width, &height);
	if (!game->wall || !game->tile || !game->flog || !game->coin || !game->exit)
	{
		printf("Error\nImage loading failed.\n");
		destroy_images(game);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		exit(1);
	}
}
