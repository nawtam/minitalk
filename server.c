/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamacha <ntamacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 13:28:05 by ntamacha          #+#    #+#             */
/*   Updated: 2025/09/17 13:28:05 by ntamacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	char_maker(int signal)
{
	static int	bit = 0;
	static char	c = 0;

	if (signal == SIGUSR1)
		c = c << 1;
	else if (signal == SIGUSR2)
		c = (c << 1) | 1;
	bit++;
	if (bit == 8)
	{
		ft_putchar(c);
		bit = 0;
		c = 0;
	}
}

int	main(void)
{
	ft_putstr("PID = ");
	ft_putnbr(getpid());
	ft_putstr("\n");
	signal(SIGUSR1, char_maker);
	signal(SIGUSR2, char_maker);
	while (1)
		pause();
}
