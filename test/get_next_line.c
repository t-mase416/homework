/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmase <tmase@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 16:50:12 by tmase             #+#    #+#             */
/*   Updated: 2025/07/24 17:00:13 by tmase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	get_char(int fd)
{
	static char	buf[BUFFER_SIZE];
	static char	*bufp;
	static int	byte = 0;

	if (byte <= 0)
	{
		byte = read(fd, buf, BUFFER_SIZE);
		if (byte < 0)
			return ('\0');
		if (byte == 0)
		{
			bufp = NULL;
			byte = 0;
			return (EOF);
		}
		bufp = buf;
	}
	byte--;
	return ((unsigned char)*bufp++);
}

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (!dest || !src)
		return (NULL);
	while (i < len)
	{
		((unsigned char *)dest)[i] = ((const unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

char	*re_malloc(char *str, size_t i, char c)
{
	size_t	len;
	char	*new_str;

	if (i >= SIZE_MAX - BUFFER_SIZE - 1)
		len = SIZE_MAX;
	else
		len = i + BUFFER_SIZE + 1;
	if (c == '\n')
		len = i + 2;
	new_str = (char *)malloc(len);
	if (!new_str)
	{
		if (str)
			free (str);
		return (NULL);
	}
	ft_memcpy(new_str, str, i);
	free(str);
	return (new_str);
}

char	*put_char(char *str, size_t *i, char c)
{
	if (c == EOF || BUFFER_SIZE == 0)
	{
		if (*i == 0)
		{
			free (str);
			str = NULL;
			return (NULL);
		}
		str[*i] = '\0';
		return (str);
	}
	if (*i % BUFFER_SIZE == 0 || c == '\n')
	{
		str = re_malloc(str, *i, c);
		if (str == NULL)
			return (NULL);
	}
	str[(*i)++] = c;
	str[*i] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	char	*line_str;
	size_t	i;
	char	c;

	i = 0;
	line_str = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		c = get_char(fd);
		if (c == '\0')
		{
			if (line_str)
				free(line_str);
			return (NULL);
		}
		line_str = put_char(line_str, &i, c);
		if (line_str == NULL)
			return (NULL);
		if (c == '\n' || c == EOF)
			return (line_str);
	}
}
