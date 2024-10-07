/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr < eduaserr@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:42:06 by eduaserr          #+#    #+#             */
/*   Updated: 2024/10/07 21:44:11 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

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
			{
				if (kill(pid, SIGUSR2) < 0)
					ft_validate_signals(pid);
			}
			else
			{
				if (kill(pid, SIGUSR1) < 0)
					ft_validate_signals(pid);
			}
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
	ft_send_bits(argv[2], pid);
	return (0);
}
