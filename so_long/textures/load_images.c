/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmase <tmase@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 18:57:28 by tmase             #+#    #+#             */
/*   Updated: 2025/07/16 19:12:27 by tmase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	load_images(t_game *game)
{
	int	width;
	int	height;

	game->wall = mlx_xpm_file_to_image(game->mlx, "wall.xpm", &width, &height);
	game->floor = mlx_xpm_file_to_image(game->mlx, "floor.xpm", &width, &height);
	game->player = mlx_xpm_file_to_image(game->mlx, "player.xpm", &width, &height);
	game->collectible = mlx_xpm_file_to_image(game->mlx, "collectible.xpm", &width, &height);
	game->exit = mlx_xpm_file_to_image(game->mlx, "exit.xpm", &width, &height);
	if (!game->wall || !game->floor || !game->player || !game->collectible || !game->exit)
	{
		printf("Error\nImage loading failed.\n");
		destroy_images(game);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		exit(1);
	}
}
