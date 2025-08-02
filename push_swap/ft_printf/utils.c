/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmase <tmase@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 17:17:24 by tmase             #+#    #+#             */
/*   Updated: 2025/05/29 22:06:12 by tmase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_character(int c)
{
	if (write(1, &c, 1) < 0)
		return (-1);
	return (1);
}

int	check_valid(char c)
{
	char	*list;

	list = "cspiduxX%";
	while (c != *list && *list)
		list++;
	if (*list == '\0')
		return (0);
	return (1);
}

int	hex_calc(unsigned long n, char flag, char *buff)
{
	char	*hex_chars;
	int		i;

	hex_chars = "0123456789abcdef";
	if (flag == 'X')
		hex_chars = "0123456789ABCDEF";
	i = 0;
	while (n > 0)
	{
		buff[i] = hex_chars[n % 16];
		n /= 16;
		i++;
	}
	return (i);
}
