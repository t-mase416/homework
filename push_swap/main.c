/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmase <tmase@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 18:57:33 by tmase             #+#    #+#             */
/*   Updated: 2025/09/14 09:27:14 by tmase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

void	display_error_and_exit(void)
{
	ft_printf("Error\n");
	exit(1);
}

t_bool	is_not_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || '9' < str[i])
			return (True);
		i++;
	}
	return (False);
}

t_bool is_not_digit_main(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if(is_not_digit(argv[i]))
			return (True);
		i++;
	}
	return (False);
}

t_bool	is_duplicate(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_strcmp(argv[i], argv[j]) == 0)
				return (True);
			j++;
		}
		i++;
	}
	return (False);
}

t_bool	is_int_overflow(char *str)
{
	long long	result;
	int			sign;

	result = 0;
	sign = 0;
	while ('0' <= *str && *str <= '9')
	{
		int digit = *str - '0';
		
	}
}

void	args_check(int argc, char **argv)
{
	if (argc < 3 || 500 < argc )
		display_error_and_exit();
	if (is_not_digit_main(argv))
		display_error_and_exit();
	if (is_duplicate(argc, argv))
		display_error_and_exit();
}

int main(int argc, char **argv)
{
	args_check(argc, argv);
}
