/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr < eduaserr@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:57:42 by eduaserr          #+#    #+#             */
/*   Updated: 2024/10/03 17:20:57 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	ft_signal_handler(int signal, siginfo_t *info, void *ucontext)
{
	static char	chr;
	static int	bit;

	(void)ucontext;
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
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_signal_handler;
	sigaction(SIGUSR2, &sa, NULL);
	sigaction(SIGUSR1, &sa, NULL);
	while (1)
		;
	return (0);
}
