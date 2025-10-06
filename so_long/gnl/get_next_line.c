/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmase <tmase@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 21:00:13 by tmase             #+#    #+#             */
/*   Updated: 2025/10/06 21:14:18 by tmase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_remaining(char *save)
{
	size_t	i;
	char	*rest;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
		return (free(save), NULL);
	rest = ft_strdup(save + i + 1);
	if (!rest)
		return (free(save), NULL);
	return (free(save), rest);
}

char	*get_one_line(char *save)
{
	size_t	i;
	char	*line;

	if (!save || !save[0])
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	ft_memcpy(line, save, i);
	line[i] = '\0';
	return (line);
}

ssize_t	read_and_join(int fd, char **save, char *buff)
{
	ssize_t	data_size;
	char	*tmp;

	data_size = read(fd, buff, BUFFER_SIZE);
	if (data_size <= 0)
		return (data_size);
	buff[data_size] = '\0';
	tmp = ft_strjoin(*save, buff);
	if (!tmp)
		return (-1);
	free(*save);
	*save = tmp;
	return (data_size);
}

char	*read_line(int fd, char *save)
{
	char	*buff;
	ssize_t	data_size;

	if (!save)
		save = ft_strdup("");
	if (!save)
		return (NULL);
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (free(save), save = NULL);
	data_size = 1;
	while (data_size > 0 && !ft_strchr(save, '\n'))
		data_size = read_and_join(fd, &save, buff);
	free(buff);
	if (data_size < 0)
		return (free(save), save = NULL);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (save)
		{
			free(save);
			save = NULL;
		}
		return (NULL);
	}
	save = read_line(fd, save);
	if (!save)
		return (NULL);
	line = get_one_line(save);
	if (!line)
		return (free(save), save = NULL);
	save = get_remaining(save);
	return (line);
}

// #include <fcntl.h>
// #include <stdio.h>

// int	main(void)
// {
// 	int fd;
// 	char *line;

// 	fd = -1;
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
//     	printf("%s\n", line);
//    		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }
