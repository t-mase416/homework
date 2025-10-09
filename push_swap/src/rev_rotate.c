/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmase <tmase@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 17:47:49 by tmase             #+#    #+#             */
/*   Updated: 2025/10/09 21:24:54 by tmase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(t_node	**stack_head)
{
	t_node	*node_to_rotate;

	if (!*stack_head || !(*stack_head)->next)
		return ;
	node_to_rotate = pop(stack_head);
	add_back(stack_head, node_to_rotate);
}

void	rra(t_stacks *stacks)
{
	if (!stacks)
		return ;
	rotate(&(stacks->a));
	ft_putstr_fd("ra\n", 1);
}

void	rrb(t_stacks *stacks)
{
	if (!stacks)
		return ;
	rotate(&(stacks->b));
	ft_putstr_fd("rb\n", 1);
}

void	rrr(t_stacks *stacks)
{
	if (!stacks)
		return ;
	rotate(&(stacks->a));
	rotate(&(stacks->b));
	ft_putstr_fd("rr\n", 1);
}
