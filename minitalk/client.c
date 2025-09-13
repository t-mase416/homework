/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmase <tmase@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 22:35:28 by tmase             #+#    #+#             */
/*   Updated: 2025/09/13 09:57:31 by tmase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	// if (argc != 3)
	// {
	// 	printf("Error: Input string and PID\n");
	// 	return (1);
	// }
	(void)argc;
	kill(atoi(argv[1]), SIGUSR1);
}
