/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmase <tmase@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 21:22:48 by tmase             #+#    #+#             */
/*   Updated: 2025/06/27 22:31:28 by tmase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static int	top_bot_check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	middle_check(char *str)
{
	int len;

	len = ft_strlen(str);
	if (*str == '1' && str[len - 1] == '1')
		return (1);
	return (0);
}

int	check_walls(char **map)
{
	int	i;

	i = 0;
	if (!top_bot_check(map[i]))
		return (0);
	i++;
	while (map[i + 1])
	{
		if (!middle_check(map[i]))
			return (0);
		i++;
	}
	if (!top_bot_check(map[i]))
		return (0);
	return (1);
}
