/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmase <tmase@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 22:48:13 by tmase             #+#    #+#             */
/*   Updated: 2025/08/01 22:57:28 by tmase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*swap_a(int *first, int *second)
{
	int		temp;

	temp = *first;
	*first = *second;
	*second = temp;
	return ("sa");
}

char	*swap_b(int *first, int *second)
{
	int		temp;

	temp = *first;
	*first = *second;
	*second = temp;
	return ("sb");
}

char	*swap_s(int *a1, int *a2, int *b1, int *b2)
{
	swap_a(a1, a2);
	swap_b(b1, b2);
	return ("ss");
}
