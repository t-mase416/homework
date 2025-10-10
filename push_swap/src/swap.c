/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmase <tmase@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 22:48:13 by tmase             #+#    #+#             */
/*   Updated: 2025/10/10 18:55:44 by tmase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node **stack_head)
{
	t_node	*first;
	t_node	*second;

	if (!stack_head || !*stack_head || !(*stack_head)->next)
		return ;
	first = *stack_head;
	second = (*stack_head)->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->next = first;
	first->prev = second;
	second->prev = NULL;
	*stack_head = second;
}

void	sa(t_stacks *stacks)
{
	swap(&(stacks->a));
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_stacks *stacks)
{
	swap(&(stacks->b));
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_stacks *stacks)
{
	swap(&(stacks->a));
	swap(&(stacks->b));
	ft_putstr_fd("ss\n", 1);
}
