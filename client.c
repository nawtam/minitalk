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

static volatile sig_atomic_t	g_ack = 0;

void	ack_handler(int sig)
{
	(void)sig;
	g_ack = 1;
}

void	send_char(pid_t pid, unsigned char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		g_ack = 0;
		if ((c >> bit) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		while (!g_ack) /* évite la course signal()/pause() */
			pause();
		bit++;
	}
}

int	main(int argc, char **argv)
{
	pid_t				pid;
	struct sigaction	act;
	int					i;

	if (argc != 3)
		return (write(2, "Usage: ./client <PID> <message>\n", 32), 1);
	pid = pid_atoi(argv[1]);
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	act.sa_handler = ack_handler;
	sigaction(SIGUSR1, &act, NULL);
	i = 0;
	while (argv[2][i])
		send_char(pid, (unsigned char)argv[2][i++]);
	send_char(pid, '\0'); /* fin de message */
	return (0);
}