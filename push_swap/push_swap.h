/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmase <tmase@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 18:58:25 by tmase             #+#    #+#             */
/*   Updated: 2025/10/17 17:04:04 by tmase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"

typedef enum e_bool
{
	False,
	True
}				t_bool;

typedef struct s_node
{
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
}				t_node;

typedef struct s_stacks
{
	t_node	*a;
	t_node	*b;
}				t_stacks;

t_node	*pop(t_node **stack_head);
t_node	*find_last_node(t_node *head);
void	args_check(int argc, char **argv);
void	add_front(t_node **stack_head, t_node *new_node);
void	add_back(t_node **stack_head, t_node *new_node);
void	display_error_and_exit(void);

void	sa(t_stacks *stacks);
void	sb(t_stacks *stacks);
void	ss(t_stacks *stacks);
void	pa(t_stacks *stacks);
void	pb(t_stacks *stacks);
void	ra(t_stacks *stacks);
void	rb(t_stacks *stacks);
void	rr(t_stacks *stacks);
void	rra(t_stacks *stacks);
void	rrb(t_stacks *stacks);
void	rrr(t_stacks *stacks);

void	sort(t_stacks *stacks);
void	cleanup_stacks(t_stacks *stacks);
t_bool	is_sorted(t_node *stack);
int		get_stack_size(t_node *stack);
void	sort_three(t_stacks *stack);
void	sort_small(t_stacks *stack);
void	sort_large(t_stacks *stacks);
void	indexing(t_node *a, int	size);

#endif
