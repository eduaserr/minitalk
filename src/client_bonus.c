/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr < eduaserr@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:56:31 by eduaserr          #+#    #+#             */
/*   Updated: 2024/10/01 17:57:19 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	send_bits(char *str, int pid)
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

int main(int argc, char **argv)
{
	int		pid;

	if (process_input(argc, argv) == 0)
		return (0);
	pid = ft_atoi(argv[1]);
	send_bits(argv[2], pid);
	return (0);
}
