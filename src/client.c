/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr < eduaserr@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:42:06 by eduaserr          #+#    #+#             */
/*   Updated: 2024/09/30 17:25:58 by eduaserr         ###   ########.fr       */
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
			usleep(42);
			bit--;
		}
	}
}

int main(int argc, char **argv)
{
	int		pid;
	char	*message;

	message = NULL;
	if (process_input(argc, argv) == 0)
		return (0);
	pid = ft_atoi(argv[1]);
	ft_printf("PID received : %d\n", pid);
	message = argv[2];
	ft_printf("message to send : %s\n", message);
	send_bits(message, pid);
	signal();
}
