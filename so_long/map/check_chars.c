/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmase <tmase@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 21:42:15 by tmase             #+#    #+#             */
/*   Updated: 2025/06/28 15:37:41 by tmase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static int	check_line_chars(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_strchr("10PEC", str[i]))
			return (False);
		i++;
	}
	return (True);
}

t_bool	check_chars(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (!check_line_chars(map[i]))
			return (False);
		i++;
	}
	return (True);
}
