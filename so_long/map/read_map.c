/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmase <tmase@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 16:29:13 by tmase             #+#    #+#             */
/*   Updated: 2025/08/18 17:33:02 by tmase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include <stdio.h>

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

static t_bool	calc_height(char *file_name, int *height)
{
	char 	*line;
	size_t 	len;
	int 	fd;

	len = 0;
	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		return (close(fd), False);
	len = ft_strlen(line);
	free(line);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (len != ft_strlen(line))
			return (close(fd), free(line), False);
		free(line);
		(*height)++;
	}
	close(fd);
	if (*height < 3)
		return (False);
	return (True);
}

t_bool	make_map(char **map, char *file_name, int height)
{
	int		fd;
	int		i;
	int		len;

	fd = open(file_name, O_RDONLY);
	i = 0;
	while (i < height)
	{
		map[i] = get_next_line(fd);
		if (!map[i])
		{
			map[i] = NULL;
			free_map(map);
			return (False);
		}
		len = ft_strlen(map[i]);
		if (len > 0 && map[i][len - 1] == '\n')
			map[i][len - 1] = '\0';
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (True);
}

char	**load_map(char *file_name)
{
	int		height;
	char	**map;

	height = 1;
	if (!calc_height(file_name, &height))
		return (NULL);
	if (height < 0)
		return (NULL);
	map = malloc(sizeof(char *) * (height + 1));
	if (!map)
		return (NULL);
	if (!make_map(map, file_name, height))
		return (NULL);
	return (map);
}
