/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmase <tmase@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 16:29:13 by tmase             #+#    #+#             */
/*   Updated: 2025/07/18 16:39:06 by tmase            ###   ########.fr       */
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

static int	calc_height(char *file_name)
{
	char 	*line;
	int		height = 1;
	size_t 	len = 0;
	int 	fd;

	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		return (close(fd), -1);
	len = ft_strlen(line);
	free(line);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (len != ft_strlen(line))
			return (close(fd), free(line), -1);
		free(line);
		height++;
	}
	close(fd);
	if (height < 3)
		return (-1);
	return (height);
}

char	**load_map(char *file_name)
{
	int		fd;
	int		i;
	int		height;
	int		len;
	char	**map;

	height = calc_height(file_name);
	if (height < 0)
		return (NULL);
	map = malloc(sizeof(char *) * (height + 1));
	if (!map)
		return (NULL);
	fd = open(file_name, O_RDONLY);
	i = 0;
	while (i < height)
	{
		map[i] = get_next_line(fd);
		if (!map[i])
		{
			map[i] = NULL;
			free_map(map);
			return (NULL);
		}
		len = ft_strlen(map[i]);
		if (len > 0 && map[i][len - 1] == '\n')
			map[i][len - 1] = '\0';
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}
