/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr < eduaserr@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:57:42 by eduaserr          #+#    #+#             */
/*   Updated: 2024/10/01 20:01:48 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	signal_handler(int signal)
{
	static char	chr;
	static int	bit;

	if (signal == SIGUSR2)
		chr |= 1;
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", chr);
		chr = 0;
		bit = 0;
	}
	else
		chr <<= 1;
}

int	main()
{
	pid_t	pid;

	pid = getpid();
	ft_printf("PID : %d\n", pid);
	ft_printf("\033[5m\033[90mtok tok...\033[0m\n");
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		pause();
	return (0);
}
