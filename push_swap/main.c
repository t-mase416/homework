/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmase <tmase@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 18:57:33 by tmase             #+#    #+#             */
/*   Updated: 2025/10/10 19:18:17 by tmase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

static t_node	*create_new_node(int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		display_error_and_exit();
	new_node->value = value;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

static void	initialize_stack(t_stacks *stacks, int argc, char **argv)
{
	t_node	*new_node;
	int		i;

	i = 0;
	while (i < argc)
	{
		new_node = create_new_node(ft_atoi(argv[i]));
		add_back(&(stacks->a), new_node);
		i++;
	}
}

int main(int argc, char **argv)
{
	t_stacks	stacks;

	if (argc < 2)
		return (0);
	stacks.a = NULL;
	stacks.b = NULL;
	args_check(argc - 1, argv + 1);
	initialize_stack(&stacks, argc - 1, argv + 1);
	sort(&stacks);
	cleanup_stacks(&stacks);
	return (0);
}
