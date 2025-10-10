/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmase <tmase@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 17:47:49 by tmase             #+#    #+#             */
/*   Updated: 2025/10/10 14:42:55 by tmase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(t_node	**stack_head)
{
	t_node	*last_node;
	t_node	*second_last;

	if (!stack_head || !*stack_head || !(*stack_head)->next)
		return ;
	last_node = find_last_node(*stack_head);
	second_last = last_node->prev;
	add_front(stack_head, last_node);
}

void	rra(t_stacks *stacks)
{
	if (!stacks)
		return ;
	rev_rotate(&(stacks->a));
	ft_putstr_fd("ra\n", 1);
}

void	rrb(t_stacks *stacks)
{
	if (!stacks)
		return ;
	rev_rotate(&(stacks->b));
	ft_putstr_fd("rb\n", 1);
}

void	rrr(t_stacks *stacks)
{
	if (!stacks)
		return ;
	rev_rotate(&(stacks->a));
	rev_rotate(&(stacks->b));
	ft_putstr_fd("rr\n", 1);
}
