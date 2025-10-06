/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_components.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmase <tmase@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 21:22:44 by tmase             #+#    #+#             */
/*   Updated: 2025/10/06 19:27:22 by tmase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static void	calc_components(char *str, int *p_count, int *e_count, int *c_count)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'P')
			(*p_count)++;
		else if (str[i] == 'E')
			(*e_count)++;
		else if (str[i] == 'C')
			(*c_count)++;
		i++;
	}
	return ;
}

t_bool	check_components(char **map)
{
	int	i;
	int	p_count;
	int	e_count;
	int	c_count;

	p_count = 0;
	e_count = 0;
	c_count = 0;
	i = 0;
	while (map[i])
	{
		calc_components(map[i], &p_count, &e_count, &c_count);
		if (p_count > 1 || e_count > 1)
			return (False);
		i++;
	}
	if (p_count != 1 || e_count != 1 || c_count < 1)
		return (False);
	return (True);
}
