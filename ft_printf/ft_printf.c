/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmase <tmase@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:48:39 by tmase             #+#    #+#             */
/*   Updated: 2025/06/12 16:50:20 by tmase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_format(const char *fmt, va_list args)
{
	int	count;

	count = 0;
	if (*fmt == 'c')
		count += print_character(va_arg (args, int));
	else if (*fmt == 's')
		count += print_string(va_arg(args, char *));
	else if (*fmt == 'p')
		count += print_pointer(va_arg(args, void *));
	else if (*fmt == 'i' || *fmt == 'd')
		count += print_integer(va_arg(args, int));
	else if (*fmt == 'u')
		count += print_uint(va_arg(args, unsigned int));
	else if (*fmt == 'x' || *fmt == 'X')
	{
		if (*fmt == 'x')
			count += print_hex(va_arg(args, unsigned int), 'x');
		else
			count += print_hex(va_arg(args, unsigned int), 'X');
	}
	else if (*fmt == '%')
		count += print_character('%');
	return (count);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		count;

	if (!fmt)
		return (-1);
	count = 0;
	va_start(args, fmt);
	while (*fmt)
	{
		if (*fmt == '%' && check_valid(*(fmt + 1)))
		{
			count += handle_format((fmt + 1), args);
			fmt += 2;
			continue ;
		}
		if (write (1, fmt, 1) < 0)
			return (-1);
		fmt++;
		count++;
	}
	va_end(args);
	return (count);
}

#include <stdio.h>

int main(void)
{
	char	*p = "Hello, world!";
	int result = 0;

	result = printf("%");
	printf("%d\n", result);

	result = ft_printf("%\n");
	printf("%d\n", result);
}
