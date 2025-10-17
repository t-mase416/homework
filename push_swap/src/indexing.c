/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmase <tmase@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:56:35 by tmase             #+#    #+#             */
/*   Updated: 2025/10/17 18:45:21 by tmase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static int	*copy_stack(t_node *a, int size)
{
	int		i;
	int		*array;
	t_node	*current;

	i = 0;
	current = a;
	array = malloc(sizeof(int) * size);
	if (!array)
		display_error_and_exit();
	while (current)
	{
		array[i] = current->value;
		i++;
		current = current->next;
	}
	return (array);
}

static void	sort_array(int *array, int size)
{
	int	i;
	int	j;
	int	swapped;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		swapped = 0;
		while (j < size - i - 1)
		{
			if (array[j] > array[j + 1])
			{
				ft_swap(&(array[j]), &(array[j + 1]));
				swapped = 1;
			}
			j++;
		}
		if (swapped == 0)
			break ;
		i++;
	}
}

static int	binary_search(int *array, int size, int value_to_find)
{
	int	left;
	int	right;
	int	mid;

	left = 0;
	right = size - 1;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (array[mid] == value_to_find)
			return (mid);
		else if (array[mid] < value_to_find)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return (-1);
}

void	indexing(t_node *a, int size)
{
	t_node	*current;
	int		index;
	int		*array;

	array = copy_stack(a, size);
	sort_array(array, size);
	current = a;
	while (current != NULL)
	{
		index = binary_search(array, size, current->value);
		if (index < 0)
		{
			free(array);
			display_error_and_exit();
		}
		current->value = index;
		current = current->next;
	}
	free(array);
}
