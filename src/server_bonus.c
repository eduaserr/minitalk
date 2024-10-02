/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr < eduaserr@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:57:42 by eduaserr          #+#    #+#             */
/*   Updated: 2024/10/02 20:21:09 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	signal_handler(int signal, siginfo_t *info, void *context)
{
	static char	chr;
	static int	bit;

	(void)context;
	if (signal == SIGUSR2)
	{
		chr |= (1 << (7 - bit));
		kill(info->si_pid, SIGUSR2);
	}
	kill(info->si_pid, SIGUSR1);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", chr);
		chr = 0;
		bit = 0;
	}
}

int	main()
{
	pid_t				pid;
	struct sigaction	sa;

	pid = getpid();
	ft_printf("PID : %d\n", pid);
	ft_printf("\033[5m\033[90mtok tok...\033[0m\n");
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR2, &sa, 0);
	sigaction(SIGUSR1, &sa, 0);
	while (1)
		pause();
	return (0);
}
