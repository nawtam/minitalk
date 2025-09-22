/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamacha <ntamacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 16:05:20 by ntamacha          #+#    #+#             */
/*   Updated: 2025/09/18 16:05:20 by ntamacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(int pid, char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if ((c >> bit) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
		bit--;
	}
}

int	main(int ac, char **av)
{
	int		pid;
	char	*msg;
	int		i;

	if (ac != 3)
		return (1);
	pid = pid_atoi(av[1]);
	msg = av[2];
	i = 0;
	while (msg[i])
	{
		send_char(pid, msg[i]);
		i++;
	}
	return (0);
}
