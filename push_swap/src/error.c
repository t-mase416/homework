/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmase <tmase@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 02:38:53 by tmase             #+#    #+#             */
/*   Updated: 2025/10/12 23:54:52 by tmase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_bool	ft_is_number(const char *str)
{
	if (!str || !*str)
		return (False);
	if (*str == '-' || *str == '+')
		str++;
	if (!*str)
		return (False);
	while (*str)
	{
		if (!ft_isdigit((unsigned char)*str))
			return (False);
		str++;
	}
	return (True);
}

static t_bool	is_int_overflow(const char *str)
{
	long long	result;
	int			digit;
	int			sign;

	result = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while ('0' <= *str && *str <= '9' && *str)
	{
		digit = *str - '0';
		if (sign == 1 && (result > INT_MAX / 10
				|| (result == INT_MAX / 10 && digit > 7)))
			return (False);
		if (sign == -1 && (result > INT_MAX / 10 + 1
				|| (result == INT_MAX / 10 && digit > 8)))
			return (False);
		result = result * 10 + digit;
		str++;
	}
	return (True);
}

t_bool	ft_is_valid_list(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (!ft_is_number(argv[i]))
			return (False);
		if (!is_int_overflow(argv[i]))
			return (False);
		i++;
	}
	return (True);
}

static t_bool	is_duplicate(int argc, char **argv)
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

void	args_check(int argc, char **argv)
{
	if (argc < 2 || 500 < argc)
		display_error_and_exit();
	if (!ft_is_valid_list(argv))
		display_error_and_exit();
	if (is_duplicate(argc, argv))
		display_error_and_exit();
}
