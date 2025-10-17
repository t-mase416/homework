/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmase <tmase@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 14:05:57 by tmase             #+#    #+#             */
/*   Updated: 2025/10/17 17:09:31 by tmase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	radix_sort(t_stacks *stacks, int size)
{
	int	max_bits;
	int	i;
	int	j;
	int	num;

	max_bits = 0;
	while (((size - 1) >> max_bits) != 0)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			num = stacks->a->value;
			if (((num >> i) & 1) == 1)
				ra(stacks);
			else
				pb(stacks);
			j++;
		}
		while (get_stack_size(stacks->b) != 0)
			pa(stacks);
		i++;
	}
}

void	sort_large(t_stacks *stacks)
{
	int	size;

	size = get_stack_size(stacks->a);
	indexing(stacks->a, size);
	radix_sort(stacks, size);
}
