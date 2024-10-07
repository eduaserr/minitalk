/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr < eduaserr@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:57:42 by eduaserr          #+#    #+#             */
/*   Updated: 2024/10/07 22:16:10 by eduaserr         ###   ########.fr       */
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
		if (kill(info->si_pid, SIGUSR2) < 0)
			exit(EXIT_FAILURE);
	}
	if (kill(info->si_pid, SIGUSR1) < 0)
		exit(EXIT_FAILURE);
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
	pid_t				pid;
	struct sigaction	sa;

	pid = getpid();
	ft_printf("PID : %d\n", pid);
	ft_printf("\033[5m\033[90mtok tok...\033[0m\n");
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_signal_handler;
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		exit(EXIT_FAILURE);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		exit(EXIT_FAILURE);
	while (1)
		pause();
	return (0);
}
