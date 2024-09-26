/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr < eduaserr@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:56:06 by eduaserr          #+#    #+#             */
/*   Updated: 2024/09/26 16:58:18 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../inc/minitalk.h"

void	get_PID()
{
}
__sighandler_t	*signal_handler()
{
	if (2 == 2)
		printf("2");
	return (0);
}

int main()
{
	signal(SIGUSR1, *signal_handler());
	signal(SIGUSR2, *signal_handler());
}
