/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmase <tmase@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:02:25 by tmase             #+#    #+#             */
/*   Updated: 2025/09/28 20:06:40 by tmase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	print_string(char *s)
{
	int	count;

	count = 0;
	if (!s)
	{
		if (write(1, "(null)", 6) < 0)
			return (-1);
		count = 6;
		return (count);
	}
	while (s[count])
	{
		print_character(s[count]);
		count++;
	}
	return (count);
}

int	print_pointer(void *ptr)
{
	int				count;
	unsigned long	address;

	count = 0;
	if (ptr == NULL)
	{
		if (write(1, "(nil)", 5) < 0)
			return (-1);
		return (5);
	}
	if (write(1, "0x", 2) < 0)
		return (-1);
	count += 2;
	address = (unsigned long)ptr;
	if (address == 0)
	{
		if (write (1, "0", 1) < 0)
			return (-1);
		return (count + 1);
	}
	count += print_hex(address, 'x');
	return (count);
}

int	print_integer(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		count = print_string("-2147483648");
		return (count);
	}
	if (n < 0)
	{
		if (write(1, "-", 1) < 0)
			return (-1);
		count++;
		n = -n;
	}
	if (n >= 10)
		count += print_integer(n / 10);
	count += print_character((n % 10) + '0');
	return (count);
}

int	print_uint(unsigned int uint)
{
	unsigned int	count;

	count = 0;
	if (uint <= INT_MAX)
		return (print_integer(uint));
	if (uint >= 10)
		count += print_uint(uint / 10);
	count += print_character((uint % 10) + '0');
	return (count);
}

int	print_hex(unsigned long n, char flag)
{
	char	buff[20];
	int		i;
	int		count;

	i = 0;
	if (n == 0)
	{
		if (write(1, "0", 1) < 0)
			return (-1);
		count = 1;
		return (count);
	}
	i = hex_calc(n, flag, buff);
	count = i;
	while (i > 0)
	{
		i--;
		if (write(1, &buff[i], 1) < 0)
			return (-1);
	}
	return (count);
}
