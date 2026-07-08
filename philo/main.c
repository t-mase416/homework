/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmase <tmase@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 05:48:09 by tmase           #+#    #+#             */
/*   Updated: 2026/05/26 03:39:28 by tmase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_config	cfg;
	t_table		table;

	if (parse_config(ac, av, &cfg) == -1)
		return (1);
	if (table_init(&table, &cfg) == -1)
		return (1);
	if (simulation_run(&table) == -1)
		return (table_destroy(&table), 1);
	table_destroy(&table);
	return (0);
}
