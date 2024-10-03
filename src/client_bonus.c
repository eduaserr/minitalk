/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr < eduaserr@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:56:31 by eduaserr          #+#    #+#             */
/*   Updated: 2024/10/03 19:17:56 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	ft_confirmation_signal(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("bit received : 0\n");
	if (signal == SIGUSR2)
		ft_printf("bit received : 1\n");
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
			if (str[i] & (1 << bit))
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(100);
			bit--;
		}
	}
}

int	main(int argc, char **argv)
{
	int		pid;

	if (ft_process_input(argc, argv) == 0)
		return (0);
	pid = ft_atoi(argv[1]);
	signal(SIGUSR1, ft_confirmation_signal);
	signal(SIGUSR2, ft_confirmation_signal);
	ft_send_bits(argv[2], pid);
	return (0);
}
