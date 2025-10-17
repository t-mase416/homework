/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmase <tmase@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 18:57:33 by tmase             #+#    #+#             */
/*   Updated: 2025/10/17 19:34:55 by tmase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	stacks.a = NULL;
	stacks.b = NULL;
	setup_stacks(&stacks, argc, argv);
	sort(&stacks);
	cleanup_stacks(&stacks);
	return (0);
}
