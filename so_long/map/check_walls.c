/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmase <tmase@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 21:22:48 by tmase             #+#    #+#             */
/*   Updated: 2025/06/28 15:41:13 by tmase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static t_bool	top_bot_check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1')
			return (False);
		i++;
	}
	return (True);
}

static t_bool	middle_check(char *str)
{
	int len;

	len = ft_strlen(str);
	if (*str == '1' && str[len - 1] == '1')
		return (True);
	return (False);
}

t_bool	check_walls(char **map)
{
	int	i;

	i = 0;
	if (!top_bot_check(map[i]))
		return (False);
	i++;
	while (map[i + 1])
	{
		if (!middle_check(map[i]))
			return (False);
		i++;
	}
	if (!top_bot_check(map[i]))
		return (False);
	return (True);
}
