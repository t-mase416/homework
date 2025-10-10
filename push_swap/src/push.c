/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmase <tmase@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 22:57:56 by tmase             #+#    #+#             */
/*   Updated: 2025/10/10 14:32:42 by tmase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stacks *stacks)
{
	t_node	*node_to_push;

	if (!stacks || !stacks->b)
		return ;
	node_to_push = pop(&(stacks->b));
	add_front(&(stacks->a), node_to_push);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stacks *stacks)
{
	t_node	*node_to_push;

	if (!stacks || !stacks->a)
		return ;
	node_to_push = pop(&(stacks->a));
	add_front(&(stacks->b), node_to_push);
	ft_putstr_fd("pb\n", 1);
}
