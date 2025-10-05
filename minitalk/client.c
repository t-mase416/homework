/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmase <tmase@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 22:35:28 by tmase             #+#    #+#             */
/*   Updated: 2025/10/05 21:14:10 by tmase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"

volatile sig_atomic_t	g_ack_received = 0;

static int	ft_is_number(const char *str)
{
	if (!str || !*str)
		return (0);
	while (*str)
	{
		if (!ft_isdigit((unsigned char)*str))
			return (0);
		str++;
	}
	return (1);
}

static int	validate_args(int ac, char **av, int *server_pid)
{
	if (ac != 3)
	{
		ft_putstr_fd("Usage: ./client <server_pid> <message>\n", 2);
		return (1);
	}
	if (!ft_is_number(av[1]))
	{
		ft_putstr_fd("Error: server_pid must be a number\n", 2);
		return (1);
	}
	*server_pid = ft_atoi(av[1]);
	if (*server_pid <= 1)
	{
		ft_putstr_fd("Error: invalid PID", 2);
		return (1);
	}
	if (kill(*server_pid, 0) == -1)
	{
		ft_putstr_fd("Error: server process not found", 2);
		return (1);
	}
	return (0);
}

static void	ack_handler(int signum)
{
	(void)signum;
	g_ack_received = 1;
}

static void	send_bit(int c, int server_pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		g_ack_received = 0;
		if ((c >> i) & 1)
			kill(server_pid, SIGUSR2);
		else
			kill(server_pid, SIGUSR1);
		while (g_ack_received == 0)
			usleep(100);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	len;
	int	server_pid;

	if (validate_args(argc, argv, &server_pid))
		return (1);
	signal(SIGUSR1, ack_handler);
	i = 0;
	len = ft_strlen(argv[2]);
	while (i < len)
	{
		send_bit(argv[2][i], server_pid);
		i++;
	}
	send_bit('\0', server_pid);
	return (0);
}
