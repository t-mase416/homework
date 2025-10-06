/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_goal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmase <tmase@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 13:06:26 by tmase             #+#    #+#             */
/*   Updated: 2025/10/06 19:31:38 by tmase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

char	**map_copy(char **original_map, int height)
{
	int		i;
	char	**copied_map;

	copied_map = malloc(sizeof(char *) * (height + 1));
	if (!copied_map)
		return (NULL);
	i = 0;
	while (original_map[i])
	{
		copied_map[i] = ft_strdup(original_map[i]);
		i++;
	}
	copied_map[i] = NULL;
	return (copied_map);
}

void	get_coordinate(char **map, t_coordinate *var, char c)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != c && map[i][j])
			j++;
		if (map[i][j] == c)
			break ;
		i++;
	}
	var->x = j;
	var->y = i;
}

void	flood_fill(char **copied_map, int x, int y)
{
	if (copied_map[y][x] == 'F' || copied_map[y][x] == '1')
		return ;
	copied_map[y][x] = 'F';
	flood_fill(copied_map, x, y + 1);
	flood_fill(copied_map, x - 1, y);
	flood_fill(copied_map, x, y - 1);
	flood_fill(copied_map, x + 1, y);
}

t_bool	cmp_maps(char **original_map, char **copied_map)
{
	t_coordinate	exit;
	int				i;
	int				j;

	get_coordinate(original_map, &exit, 'E');
	if (copied_map[exit.y][exit.x] != 'F')
		return (False);
	i = 0;
	while (original_map[i])
	{
		j = 0;
		while (original_map[i][j])
		{
			if (original_map[i][j] == 'C' && copied_map[i][j] != 'F')
				return (False);
			j++;
		}
		i++;
	}
	return (True);
}

t_bool	check_goal(char **original_map)
{
	char			**copied_map;
	int				height;
	t_coordinate	start;

	height = get_map_size(original_map);
	copied_map = map_copy(original_map, height);
	if (!copied_map)
		return (False);
	get_coordinate(original_map, &start, 'P');
	flood_fill(copied_map, start.x, start.y);
	if (!cmp_maps(original_map, copied_map))
		return (False);
	free_map(copied_map);
	return (True);
}
