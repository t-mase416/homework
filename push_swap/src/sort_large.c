/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmase <tmase@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 15:21:08 by tmase             #+#    #+#             */
/*   Updated: 2025/10/16 15:21:20 by tmase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_target_pos_in_b(t_node *stack_b, int value_a)
{
	int		target_pos;
	t_node	*current_b;
	int		closest_smaller;
	int		max_val;
	int		max_pos;
	int		pos;

	target_pos = 0;
	current_b = stack_b;
	closest_smaller = INT_MIN;
	max_val = INT_MIN;
	max_pos = 0;
	pos = 0;
	while (current_b)
	{
		if (current_b->value < value_a && current_b->value > closest_smaller)
		{
			closest_smaller = current_b->value;
			target_pos = pos;
		}
		if (current_b->value > max_val)
		{
			max_val = current_b->value;
			max_pos = pos;
		}
		current_b = current_b->next;
		pos++;
	}
	if (closest_smaller == INT_MIN)
		return (max_pos);
	return (target_pos);
}

// AとBの移動コストを計算
static void	calculate_costs(t_stacks *stacks, t_node *node_a, int pos_a, int *cost_a, int *cost_b)
{
	int	size_a;
	int	size_b;
	int	pos_b;

	size_a = get_stack_size(stacks->a);
	size_b = get_stack_size(stacks->b);
	pos_b = find_target_pos_in_b(stacks->b, node_a->value);
	if (pos_a <= size_a / 2)
		*cost_a = pos_a;
	else
		*cost_a = -(size_a - pos_a);
	if (pos_b <= size_b / 2)
		*cost_b = pos_b;
	else
		*cost_b = -(size_b - pos_b);
}

// 最もコストの低いノードを探索し、移動
static void	find_cheapest_and_move(t_stacks *stacks)
{
	t_node	*current_a;
	int		cheapest_cost;
	int		final_cost_a;
	int		final_cost_b;
	int		pos;

	current_a = stacks->a;
	cheapest_cost = INT_MAX;
	final_cost_a = 0;
	final_cost_b = 0;
	pos = 0;
	while (current_a)
	{
		int	cost_a;
		int	cost_b;
		int	total_cost;

		calculate_costs(stacks, current_a, pos, &cost_a, &cost_b);
		if (cost_a >= 0 && cost_b >= 0)
			total_cost = (cost_a > cost_b) ? cost_a : cost_b;
		else if (cost_a < 0 && cost_b < 0)
			total_cost = (abs(cost_a) > abs(cost_b)) ? abs(cost_a) : abs(cost_b);
		else
			total_cost = abs(cost_a) + abs(cost_b);
		if (total_cost < cheapest_cost)
		{
			cheapest_cost = total_cost;
			final_cost_a = cost_a;
			final_cost_b = cost_b;
		}
		current_a = current_a->next;
		pos++;
	}
	while (final_cost_a > 0 && final_cost_b > 0)
	{
		rr(stacks);
		final_cost_a--;
		final_cost_b--;
	}
	while (final_cost_a < 0 && final_cost_b < 0)
	{
		rrr(stacks);
		final_cost_a++;
		final_cost_b++;
	}
	while (final_cost_a > 0)
	{
		ra(stacks);
		final_cost_a--;
	}
	while (final_cost_a < 0)
	{
		rra(stacks);
		final_cost_a++;
	}
	while (final_cost_b > 0)
	{
		rb(stacks);
		final_cost_b--;
	}
	while (final_cost_b < 0)
	{
		rrb(stacks);
		final_cost_b++;
	}
	pb(stacks);
}

static int	find_min_val_pos(t_node *stack)
{
	int	min_val;
	int	min_pos;
	int	pos;

	min_val = INT_MAX;
	min_pos = 0;
	pos = 0;
	while (stack)
	{
		if (stack->value < min_val)
		{
			min_val = stack->value;
			min_pos = pos;
		}
		stack = stack->next;
		pos++;
	}
	return (min_pos);
}

void	sort_large(t_stacks *stacks)
{
	int	min_pos;
	int	size_a;

	pb(stacks);
	pb(stacks);
	while (get_stack_size(stacks->a) > 3)
	{
		find_cheapest_and_move(stacks);
	}
	sort_three(stacks);
	while (stacks->b)
	{
		pa(stacks);
	}
	min_pos = find_min_val_pos(stacks->a);
	size_a = get_stack_size(stacks->a);
	if (min_pos <= size_a / 2)
	{
		while (min_pos-- > 0)
			ra(stacks);
	}
	else
	{
		while (min_pos++ < size_a)
			rra(stacks);
	}
}
