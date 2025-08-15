/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmase <tmase@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 22:48:13 by tmase             #+#    #+#             */
/*   Updated: 2025/08/02 19:57:37 by tmase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(int *first, int *second)
{
	int		temp;

	temp = *first;
	*first = *second;
	*second = temp;
	ft_printf("sa\n");
}

void	swap_b(int *first, int *second)
{
	int		temp;

	temp = *first;
	*first = *second;
	*second = temp;
	ft_printf("sb\n");
}

void	swap_s(int *a1, int *a2, int *b1, int *b2)
{
	swap_a(a1, a2);
	swap_b(b1, b2);
	ft_printf("ss\n");
}
