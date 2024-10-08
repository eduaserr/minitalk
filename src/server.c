/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr < eduaserr@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:56:06 by eduaserr          #+#    #+#             */
/*   Updated: 2024/10/07 22:20:45 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	signal_handler(int signal)
{
	static char	chr;
	static int	bit;

	if (signal == SIGUSR2)
		chr |= (1 << (7 - bit));
	bit++;
	if (bit == 8)
	{
		write(1, &chr, 1);
		chr = 0;
		bit = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("PID : %d\n", pid);
	ft_printf("\033[5m\033[90mwaiting...\033[0m\n");
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		pause();
	return (0);
}
