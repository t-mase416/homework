/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmase <tmase@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 16:18:22 by tmase             #+#    #+#             */
/*   Updated: 2025/06/27 22:06:08 by tmase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	MAP_H
# define MAP_H

#include "../gnl/get_next_line.h"
#include "../libft/libft.h"
#include <fcntl.h>

int	check_walls(char **map);
int	check_components(char **map);
int	check_chars(char **map);
int	check_valid_map(char **map);

char	**load_map(char *file_name);



#endif
