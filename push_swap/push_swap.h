/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmase <tmase@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 18:58:25 by tmase             #+#    #+#             */
/*   Updated: 2025/08/14 17:53:47 by tmase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


#include <stdlib.h>
#include <stdio.h>
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

typedef enum	e_bool{
	False,
	True
}				t_bool;

typedef	struct	s_stack{
	int	num;
	t_stack	next;
}				t_stack;


void	swap_a(int *first, int *second);
void	swap_b(int *first, int *second);
void	swap_s(int *a1, int *a2, int *b1, int *b2);

#endif
