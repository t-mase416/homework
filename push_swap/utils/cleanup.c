/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmase <tmase@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 19:16:18 by tmase             #+#    #+#             */
/*   Updated: 2025/10/10 20:29:18 by tmase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_stack(t_node **stack_head)
{
	t_node	*current;
	t_node	*temp;

	if (!stack_head || !*stack_head)
		return ;
	current = *stack_head;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	*stack_head = NULL;
}

void	cleanup_stacks(t_stacks *stacks)
{
	free_stack(&(stacks->a));
	free_stack(&(stacks->b));
}
