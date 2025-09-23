/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmase <tmase@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 22:35:31 by tmase             #+#    #+#             */
/*   Updated: 2025/09/19 20:19:24 by tmase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void	sig_handler(int signum, siginfo_t *info, void *context)
{
	static unsigned char	c;
	static int				bit_count;
	pid_t					client_pid;

	(void)context;
	client_pid = info->si_pid;
	if (signum == SIGUSR2)
		c |= (1 << bit_count);
	bit_count++;
	if (bit_count == 8)
	{
		if (c == '\0')
			write(1, "\n", 1);
		else
			write(1, &c, 1);
		bit_count = 0;
		c = 0;
	}
	usleep(50);
	kill(client_pid, SIGUSR1);
}

int main(void)
{
	pid_t				my_pid;
	struct sigaction	sa;

	my_pid = getpid();
	printf("PID : %d\n", my_pid);
	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = &sig_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while(1)
		pause();
	return(0);
}
