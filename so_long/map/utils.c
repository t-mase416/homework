/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmase <tmase@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 19:31:49 by tmase             #+#    #+#             */
/*   Updated: 2025/10/06 19:33:39 by tmase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	get_map_size(char **map)
{
	int	height;

	height = 0;
	while (map[height])
		height++;
	return (height);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
