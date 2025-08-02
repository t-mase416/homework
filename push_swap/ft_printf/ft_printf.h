/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmase <tmase@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 17:56:21 by tmase             #+#    #+#             */
/*   Updated: 2025/05/29 23:10:55 by tmase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <limits.h>
# include <stdarg.h>

int	ft_printf(const char *fmt, ...);

int	handle_format(const char *fmt, va_list args);

int	print_pointer(void *ptr);

int	print_hex(unsigned long n, char flag);

int	print_string(char *s);

int	print_integer(int n);

int	print_uint(unsigned int uint);

int	print_character(int c);

int	check_valid(char c);

int	hex_calc(unsigned long n, char flag, char *buff);

#endif
