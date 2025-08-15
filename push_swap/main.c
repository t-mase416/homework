/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmase <tmase@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 18:57:33 by tmase             #+#    #+#             */
/*   Updated: 2025/08/14 17:44:28 by tmase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool	is_number(char *str)
{
	while(str)
	{
		ft_isdigit(*str);
		str++;
	}
}

static t_bool	args_error(int argc, char **argv)
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

t_stack	*create_stack(char **argv)
{
	t_stack	*a_stack;

	a_stack->num = ft_atoi(argv[1]);
	return(a_stack);
}

int	main(int argc, char **argv)
{
	t_stack	*a_stack;
	t_stack *b_stack;

	if (!args_error(argc, **argv))
	{
		ft_printf("Error\n");
		return (1);
	}
	a_stack = create_stack(**argv);
	push_swap(a_stack, b_stack);
	return (0);
}
