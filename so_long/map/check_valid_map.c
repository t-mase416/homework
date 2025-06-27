/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmase <tmase@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 16:16:30 by tmase             #+#    #+#             */
/*   Updated: 2025/06/27 22:36:16 by tmase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	check_valid_map(char **map)
{
	if (map == NULL)
		return (0);
	if (!check_walls(map))
		return (0);
	if (!check_components(map))
		return (0);
	if (!check_chars(map))
		return (0);
	return (1);
}
