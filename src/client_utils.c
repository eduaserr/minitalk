/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr < eduaserr@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 17:54:56 by eduaserr          #+#    #+#             */
/*   Updated: 2024/09/27 18:23:15 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

int	process_input(int argc, char **argv)
{
	int		i;

	i = 0;
	if (argc != 3)
	{
		ft_printf("\x1b[31minvalid format!\n\033[0m");
		ft_printf("You must introduce : %s <PID> 'message to send'\n", argv[0]);
		return (0);
	}
	while (argv[1][i])
	{
		if (!ft_isdigit(argv[1][i]))
		{
			ft_printf("\x1b[31minvalid format!\n\033[0m");
			ft_printf("PID must only contains numbers\n");
			return (0);
		}
		i++;
	}
	if (i != 7)
		return (ft_printf("invalid PID"), 0);
	return (1);
}
