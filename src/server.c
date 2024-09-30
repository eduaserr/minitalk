/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr < eduaserr@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:56:06 by eduaserr          #+#    #+#             */
/*   Updated: 2024/09/30 16:30:48 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

int main()
{
	pid_t	pid;

	pid = getpid();
	ft_printf("PID : %d\n", pid);
	kill(pid, SIGUSR1);
	kill(pid, SIGUSR2);
	sigaction();
}
