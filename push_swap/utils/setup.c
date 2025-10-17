/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmase <tmase@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 19:25:58 by tmase             #+#    #+#             */
/*   Updated: 2025/10/17 19:39:02 by tmase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	free_split_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

static int	count_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

void	setup_stacks(t_stacks *stacks, int argc, char **argv)
{
	int		args_count;
	char	**args;

	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		args_count = count_args(args);
		args_check(args_count, args);
		initialize_stack(stacks, args_count, args);
		free_split_args(args);
	}
	else
	{
		args_check(argc - 1, argv + 1);
		initialize_stack(stacks, argc - 1, argv + 1);
	}
}
