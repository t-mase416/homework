/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmase <tmase@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 22:35:31 by tmase             #+#    #+#             */
/*   Updated: 2025/09/13 10:03:41 by tmase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void	sig_handler(int signum)
{
	if (signum == SIGUSR1)
		write(1, "SIG 1 detected", 14);
	else if (signum == SIGUSR2)
		write(1, "SIG 2 detected", 14);
}

int main(void)
{
	pid_t				my_pid;
	struct sigaction	sa;

	my_pid = getpid();
	printf("PID : %d\n", my_pid);
	sigemptyset(&sa.sa_mask);
	sa.sa_handler = &sig_handler;
	sa.sa_flags = 0;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		perror("sigaction");
		return(1);
	}
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		perror("sigaction");
		return(1);
	}
	while(1)
		pause();
	return(0);
}
