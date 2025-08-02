/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmase <tmase@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 18:57:33 by tmase             #+#    #+#             */
/*   Updated: 2025/08/01 22:47:50 by tmase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	is_number(char *str)
{
	while(str)
	{
		ft_isdigit(*str);
		str++;
	}
}

t_bool	args_error(int argc, char **argv)
{
	int	i;

	if(argc < 3 || 500 < argc)
		return (False);
	i = 0;
	while(argv[i])
	{
		if(!is_number(argv[i]))
			return (False);
		i++;
	}
	return (True);
}

void	print_list(char **list)
{
	int i;

	i = 0;
	while(list[i])
	{
		ft_printf("%s\n", list[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	char	**list;

	if (!args_error(argc, **argv))
	{
		ft_printf("Error\n");
		return (1);
	}
	list = push_swap(**argv);
	print_list(list);
	return (0);
}
