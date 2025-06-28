/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmase <tmase@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 16:16:30 by tmase             #+#    #+#             */
/*   Updated: 2025/06/28 20:32:29 by tmase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

t_bool	check_valid_map(char **map)
{
	if (map == NULL)
		return (False);
	if (!check_walls(map))
		return (False);
	if (!check_components(map))
		return (False);
	if (!check_chars(map))
		return (False);
	if (!check_goal(map))
		return (False);
	return (True);
}
