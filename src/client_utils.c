/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr < eduaserr@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 17:54:56 by eduaserr          #+#    #+#             */
/*   Updated: 2024/10/08 13:25:49 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	ft_validate_signals(int pid)
{
	if ((kill(pid, SIGUSR2) < 0) || (kill(pid, SIGUSR1) < 0))
	{
		write(1, "invalid PID\n", 12);
		exit(EXIT_FAILURE);
	}
}

int	ft_process_input(int argc, char **argv)
{
	int		i;

	i = -1;
	if (argc != 3)
	{
		ft_printf("\x1b[31minvalid format!\n\033[0m");
		ft_printf("You must introduce : %s <PID> 'message to send'\n", argv[0]);
		return (1);
	}
	while (argv[1][++i])
	{
		if (!ft_isdigit(argv[1][i]))
		{
			ft_printf("\x1b[31minvalid format!\n\033[0m");
			ft_printf("PID must only contains numbers\n");
			return (1);
		}
	}
	if (argv[1][0] == '\0')
		return (ft_printf("Empty PID\n"), 1);
	if (argv[2][0] == '\0')
		return (ft_printf("Empty message\n"), 1);
	return (0);
}
