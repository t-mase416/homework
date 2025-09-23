/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmase <tmase@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 22:35:28 by tmase             #+#    #+#             */
/*   Updated: 2025/09/19 19:59:00 by tmase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #define _POSIX_C_SOURCE 200809L

#include <signal.h>
#include "libft.h"

void	ack_handler(int signum)
{
	(void)signum;
}

void	calc_bit(int c, int server_pid)
{
	int	i;

	i = 0;
	while(i < 8)
	{
		if ((c >> i) & 1)
			kill(server_pid, SIGUSR2);
		else
			kill(server_pid, SIGUSR1);
		pause();
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	len;
	int	server_pid;

	signal(SIGUSR1, ack_handler);
	server_pid = ft_atoi(argv[1]);
	i = 0;
	len = ft_strlen(argv[2]);
	while (i < len)
	{
		calc_bit(argv[2][i], server_pid);
		i++;
	}
	calc_bit('\0', server_pid);
	return (0);
}
