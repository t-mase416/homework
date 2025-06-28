/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_goal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmase <tmase@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 13:06:26 by tmase             #+#    #+#             */
/*   Updated: 2025/06/28 16:42:27 by tmase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

typedef	struct	s_coordinate{
	int	x;
	int	y;
}				t_coordinate;

int	get_map_size(char **map)
{
	int	height;

	height = 0;
	while (map[height])
		height++;
	return (height);
}

char	**map_copy(char **original_map, int height)
{
	int	i;
	char	**copied_map;

	copied_map = malloc(sizeof(char *) * height + 1);
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

void	get_cooridinate(char **map, t_coordinate  *var, char c)
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
	var->x = i;
	var->y = j;
}

void	flood_fill(char **copied_map, int x, int y)
{
	if (copied_map[x][y] == 'F' || copied_map[x][y] == '1')
		return ;
	copied_map[x][y] = 'F';
	flood_fill(copied_map, x, y + 1);
	flood_fill(copied_map, x - 1, y);
	flood_fill(copied_map, x, y - 1);
	flood_fill(copied_map, x + 1, y);
}

t_bool	cmp_maps(char **original_map, char **copied_map)
{
	t_coordinate	collectible;
	t_coordinate	exit;
	int				i;
	int				j;

	get_cooridinate(original_map, &exit, 'E');
	if (copied_map[exit.x][exit.y] != 'F')
		return (False);
	i = 0;
	while (original_map[i])
	{
		j = 0;
		while (original_map[i][j] && original_map[i][j] != 'C')
			j++;
		if (original_map[i][j] == 'C' && copied_map[i][j] != 'F')
			return (False);
		i++;
	}
	return (True);
}

t_bool	check_goal(char **original_map)
{
	char		**copied_map;
	int			height;
	int			i;
	t_coordinate	start;

	i = 0;
	height = get_map_size(original_map);
	copied_map = map_copy(original_map, height);
	if (!copied_map)
		return (False);
	get_cooridinate(original_map, &start, 'P');
	flood_fill(copied_map, start.x, start.y);
	if (!cmp_maps(original_map, copied_map))
		return (False);
	free_map(copied_map);
	return (True);
}
