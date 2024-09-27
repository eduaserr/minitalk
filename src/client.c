/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr < eduaserr@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:42:06 by eduaserr          #+#    #+#             */
/*   Updated: 2024/09/27 18:13:37 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	get_binary(char *str, int pid)
{
	int	i;

	i = 0;
	int pid1;
	pid1 = pid;
	if (str[i])
	{
		ft_printf("binary input");
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
	//get_binary(message, pid);
	kill(pid, SIGUSR1);
}
