/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_quick.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmase <tmase@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 20:20:15 by tmase             #+#    #+#             */
/*   Updated: 2025/10/16 21:05:31 by tmase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_a_to_b(t_stacks *stacks, int size);
void sort_b_to_a(t_stacks *stacks, int size);

void	sort_small_a(t_stacks *stacks, int size)
{
	if (size == 1)
		return ;
	if (size == 2)
	{
		if (stacks->a->value > stacks->a->next->value)
			sa(stacks);
		return ;
	}
	if (size == 3)
		sort_three(stacks);
}

void	sort_small_b(t_stacks *stacks, int size)
{
	if (size == 1)
		pa(stacks);
	else if (size == 2)
	{
		if (stacks->b->value < stacks->b->next->value)
			sb(stacks);
		pa(stacks);
		pa(stacks);
	}
	else if (size == 3)
	{
		while (get_stack_size(stacks->b) > 0)
			pa(stacks);
		sort_small_a(stacks, 3);
	}
}

static void	sort_array(int *arr, int size)
{
	int	i = 0;
	int	j;
	int	tmp;

	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	find_median(t_node *stack, int size)
{
	int		*arr;
	int		i;
	int		median;
	t_node	*current;

	arr = malloc(sizeof(int) * size);
	if (!arr)
		display_error_and_exit();
	current = stack;
	i = 0;
	while (i < size && current != NULL)
	{
		arr[i] = current->value;
		current = current->next;
		i++;
	}
	sort_array(arr, size);
	median = arr[size / 2];
	free(arr);
	return (median);
}

void	sort_b_to_a(t_stacks *stacks, int size)
{
	int	pivot;
	int	pushed_a = 0;
	int rotated_b = 0;
	int	i = 0;

	if (size <= 3)
	{
		sort_small_b(stacks, size);
		return ;
	}
	pivot = find_median(stacks->b, size);
	while (i < size)
	{
		if (stacks->b->value > pivot)
		{
			pa(stacks);
			pushed_a++;
		}
		else
		{
			rb(stacks);
			rotated_b++;
		}
		i++;
	}
	sort_a_to_b(stacks, pushed_a);
	sort_b_to_a(stacks, rotated_b);
}

void	sort_a_to_b(t_stacks *stacks, int size)
{
	int	pivot;
	int	pushed_b = 0;
	int rotated_a = 0;
	int	i = 0;

	if (is_sorted(stacks->a))
		return ;
	if (size <= 3)
	{
		sort_small_a(stacks, size);
		return ;
	}
	pivot = find_median(stacks->a, size);
	while (i < size)
	{
		if (stacks->a->value <= pivot)
		{
			pb(stacks);
			pushed_b++;
		}
		else
		{
			ra(stacks);
			rotated_a++;
		}
		i++;
	}
	sort_a_to_b(stacks, rotated_a);
	sort_b_to_a(stacks, pushed_b);
}

void	sort_large(t_stacks *stacks)
{
	int	size;

	size = get_stack_size(stacks->a);
	if (!is_sorted(stacks->a))
		sort_a_to_b(stacks, size);
}
