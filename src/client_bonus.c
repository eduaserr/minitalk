/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr < eduaserr@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:56:31 by eduaserr          #+#    #+#             */
/*   Updated: 2024/10/08 13:48:06 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

volatile sig_atomic_t	g_received_signal;

void	ft_confirmation_signal(int signal)
{
	g_received_signal = 1;
	if (signal == SIGUSR1)
		write(1, "bit received : 0\n", 17);
	if (signal == SIGUSR2)
		write(1, "bit received : 1\n", 17);
}

void	ft_send_bits(char *str, int pid)
{
	int	i;
	int	bit;

	i = -1;
	while (str[++i])
	{
		bit = 7;
		while (bit >= 0)
		{
			g_received_signal = 0;
			if (str[i] & (1 << bit))
			{
				if (kill(pid, SIGUSR2) < 0)
					ft_validate_signals(pid);
			}
			else
				if (kill(pid, SIGUSR1) < 0)
					ft_validate_signals(pid);
			while (g_received_signal == 0)
				pause();
			usleep(250);
			bit--;
		}
	}
}

int	main(int argc, char **argv)
{
	int		pid;

	if (ft_process_input(argc, argv) == 1)
		return (0);
	pid = ft_atoi(argv[1]);
	signal(SIGUSR1, ft_confirmation_signal);
	signal(SIGUSR2, ft_confirmation_signal);
	ft_send_bits(argv[2], pid);
	return (0);
}
