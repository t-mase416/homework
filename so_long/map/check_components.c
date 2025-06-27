/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_components.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmase <tmase@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 21:22:44 by tmase             #+#    #+#             */
/*   Updated: 2025/06/27 21:48:02 by tmase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static void	calc_components(char *str, int *P_count, int *E_count, int *C_count)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'P')
			(*P_count)++;
		else if (str[i] == 'E')
			(*E_count)++;
		else if (str[i] == 'C')
			(*C_count)++;
		i++;
	}
	return ;
}

int	check_components(char **map)
{
	int	i;
	int	P_count;
	int	E_count;
	int	C_count;

	P_count = 0;
	E_count = 0;
	C_count = 0;
	i = 0;
	while (map[i])
	{
		calc_components(map[i], &P_count, &E_count, &C_count);
		if (P_count > 1 || E_count > 1)
			return (0);
		i++;
	}
	if (P_count != 1 || E_count != 1 || C_count < 1)
		return (0);
	return (1);
}
