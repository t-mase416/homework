/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmase <tmase@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 19:39:52 by tmase             #+#    #+#             */
/*   Updated: 2025/10/17 17:02:45 by tmase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*pop(t_node **stack_head)
{
	t_node	*first_node;

	if (!stack_head || !*stack_head)
		return (NULL);
	first_node = *stack_head;
	*stack_head = first_node->next;
	if (*stack_head)
		(*stack_head)->prev = NULL;
	first_node->next = NULL;
	first_node->prev = NULL;
	return (first_node);
}

void	add_front(t_node **stack_head, t_node *new_node)
{
	if (!new_node)
		return ;
	if (*stack_head)
		(*stack_head)->prev = new_node;
	new_node->next = *stack_head;
	*stack_head = new_node;
}

t_node	*find_last_node(t_node *head)
{
	while (head->next)
		head = head->next;
	return (head);
}

void	add_back(t_node **stack_head, t_node *new_node)
{
	t_node	*last_node;

	if (!new_node)
		return ;
	if (!*stack_head)
	{
		*stack_head = new_node;
		return ;
	}
	last_node = find_last_node(*stack_head);
	last_node->next = new_node;
	new_node->prev = last_node;
}

void	display_error_and_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
