/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmase <tmase@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 18:29:26 by tmase             #+#    #+#             */
/*   Updated: 2025/10/10 19:24:07 by tmase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool	is_sorted(t_node *stack)
{
	if (!stack)
		return (True);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (False);
		stack = stack->next;
	}
	return (True);
}

static int	get_stack_size(t_node *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

static void	sort_three(t_stacks *stacks)
{
	t_node	*head;
	int		top;
	int		middle;
	int		bottom;

	head = stacks->a;
	top = head->value;
	middle = head->next->value;
	bottom = head->next->next->value;
	if (top < middle && middle > bottom && top < bottom) //1 3 2
	{
		sa(stacks);
		ra(stacks);
	}
	else if (top > middle && middle < bottom && top < bottom) // 2 1 3
		sa(stacks);
	else if (top < middle && middle > bottom && top > bottom) // 2 3 1
		rra(stacks);
	else if (top > middle && middle < bottom && top > bottom) // 3 1 2
		ra(stacks);
	else if (top > middle && middle > bottom && top > bottom) // 3 2 1
	{
		sa(stacks);
		rra(stacks);
	}
}

void	sort(t_stacks *stacks)
{
	int	stack_size;

	stack_size = get_stack_size(stacks->a);
	if (is_sorted(stacks->a))
		return ;
	if (stack_size == 2)
		sa(stacks);
	else if (stack_size == 3)
		sort_three(stacks);
	// else if (stack_size <= 5)
	// 	sort_small(stacks);
	// else
	// 	sort_large(stacks);
}
