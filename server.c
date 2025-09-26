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

static unsigned int	g_data = 0;

void	sig_handler(int sig, siginfo_t *info, void *ucontext)
{
	unsigned char	c;

	(void)ucontext;
	if (sig == SIGUSR2)
		g_data |= (1u << (g_data >> 8));
	g_data += 0x100u;
	if ((g_data >> 8) == 8)
	{
		c = (unsigned char)g_data;
		if (c == '\0')
			write(1, "\n", 1);
		else
			write(1, &c, 1);
		g_data = 0;
	}
	kill(info->si_pid, SIGUSR1);
	usleep(500);
}

int	main(void)
{
	struct sigaction	act;

	write(1, "PID = ", 6);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	sigemptyset(&act.sa_mask);
	act.sa_sigaction = sig_handler;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		pause();
	return (0);
}