/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr < eduaserr@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:42:06 by eduaserr          #+#    #+#             */
/*   Updated: 2024/09/26 16:58:15 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../inc/minitalk.h"

__sighandler_t	*signal_handler()
{
	if (2 == 2)
		printf("2");
	return (0);
}

int main()
{
	signal(SIGUSR1, *signal_handler());
}
