/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmase <tmase@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 18:17:57 by tmase             #+#    #+#             */
/*   Updated: 2025/10/14 17:28:22 by tmase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct s_costinfo
{
	int	target_position;
	int	max_position;
	int	position;
	int	closest_smaller;
	int	max_value;
}				t_costinfo;

static int	find_target(t_node *stack_b, int value_a)
{
	t_costinfo	info;
	t_node		*current_b;

	info = (t_costinfo){0};
	current_b = stack_b;
	info.closest_smaller = INT_MIN;
	info.max_value = INT_MIN;
	while (current_b)
	{
		if (current_b->value < value_a && current_b->value > info.closest_smaller)
		{
			info.closest_smaller = current_b->value;
			info.target_position = info.position;
		}
		if (current_b->value > info.max_position)
		{
			info.max_value = current_b->value;
			info.max_position = info.position;
		}
		current_b = current_b->next;
		info.position++;
	}
	if (info.closest_smaller == INT_MIN)
		return (info.max_position);
	return (info.target_position);
}

void	sort_large(t_stacks *stacks)
{
	pb(stacks);
	pb(stacks);
	while (get_stack_size(stacks->a) > 3)
	{
		find_target(stacks->b, ); //各ノード構造体にターゲットを追加
		calc_cost(stacks); //各ノード構造体に移動コストを追加
		push_lowcost(stacks); //AとBをコスト分rotateさせてBからAにプッシュ
	}
	sort_three(stacks);
	while (stacks->b)
		push_remaining(stacks);
}
