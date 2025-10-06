/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmase <tmase@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 16:18:22 by tmase             #+#    #+#             */
/*   Updated: 2025/10/06 19:30:34 by tmase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "../gnl/get_next_line.h"
# include "../libft/libft.h"
# include <fcntl.h>

typedef enum e_bool
{
	False,
	True
}			t_bool;

typedef struct s_coordinate
{
	int	x;
	int	y;
}				t_coordinate;

t_bool	check_walls(char **map);
t_bool	check_components(char **map);
t_bool	check_chars(char **map);
t_bool	check_goal(char **original_map);
t_bool	check_valid_map(char **map);

void	free_map(char **map);
char	**load_map(char *file_name);
int		get_map_size(char **map);

#endif