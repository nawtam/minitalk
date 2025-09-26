/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamacha <ntamacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 18:38:01 by ntamacha          #+#    #+#             */
/*   Updated: 2025/09/22 18:38:01 by ntamacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h> //signal + kill
# include <unistd.h>
# include <stdlib.h>

void	send_char(pid_t pid, unsigned char c);
void	sig_handler(int sig, siginfo_t *info, void *ucontext);
void	ack_handler(int sig);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int n);
int     pid_atoi(char *pid);

#endif
