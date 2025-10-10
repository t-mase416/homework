/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmase <tmase@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 20:09:03 by tmase             #+#    #+#             */
/*   Updated: 2025/10/10 20:21:38 by tmase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*find_min_node(t_node *stack)
{
	t_node *min_node;

	if (!stack)
		return (NULL);
	min_node = stack;
	while (stack)
	{
		if (stack->value < min_node->value)
			min_node = stack;
		stack = stack->next;
	}
	return (min_node);
}

static void	push_min_to_b(t_stacks *stacks)
{
	t_node	*min_node;
	t_node	*current;
	int		size;
	int		i;

	min_node = find_min_node(stacks->a);
	size = get_stack_size(stacks->a);
	i = 0;
	current = stacks->a;
	while (current != min_node)
	{
		current = current->next;
		i++;
	}
	if (i <= size / 2)
	{
		while (stacks->a != min_node)
			ra(stacks);
	}
	else
	{
		while (stacks->a != min_node)
			rra(stacks);
	}
	pb(stacks);
}

void	sort_small(t_stacks *stacks)
{
	while (get_stack_size(stacks->a) > 3)
		push_min_to_b(stacks);
	sort_three(stacks);
	while (stacks->b)
		pa(stacks);
}
