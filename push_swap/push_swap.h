/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmase <tmase@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 18:58:25 by tmase             #+#    #+#             */
/*   Updated: 2025/10/09 19:42:13 by tmase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


#include <stdlib.h>
#include <stdio.h>
#include "libft/libft.h"

typedef enum e_bool
{
	False,
	True
}				t_bool;

typedef struct s_node
{
	int	value;
	struct s_node	*prev;
	struct s_node	*next;
}				t_node;

typedef struct s_stacks
{
	t_node *a;
	t_node *b;
}				t_stacks;

void	args_check(int argc, char **argv);
t_node	*pop(t_node **stack_head);
void	add_front(t_node **stack_head, t_node *new_node);
t_node	*find_last_node(t_node *head);
void	add_back(t_node **stack_head, t_node *new_node);

#endif
