/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 19:40:51 by junsyun           #+#    #+#             */
/*   Updated: 2022/10/02 00:23:57 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_rcv_status;

static void	message_end()
{	
	ft_printf("\n\t%s\t\n", "server received!");
}

static void	handler(int sig, siginfo_t *info, void *ucontext)
{
	(void)info;
	(void)ucontext;
	if (sig == SIGUSR1)
		g_rcv_status = 1;
	if (sig == SIGUSR2)
		message_end();
}

static void	send_message(char *msg, size_t length, pid_t pid)
{
	size_t	i;
	size_t	j;
	int		bit;
	int		signal;

	i = 0;
	while (i < length)
	{
		j = 0;
		while (j < 8)
		{
			bit = (msg[i] >> j) & 1;
			g_rcv_status = 0;
			if ((bit & 1) == 0)
				signal = SIGUSR1;
			else
				signal = SIGUSR2;
			exec_kill(pid, signal);
			while (!g_rcv_status)
				usleep(50);
			j++;
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	struct sigaction	sig_act_msgchk;
	pid_t				pid;
	char				*msg;

	if (argc != 3)
		return (1);
	pid = (pid_t)get_pid_integer(argv[1]);
	msg = argv[2];
	sig_act_msgchk.sa_flags = SA_SIGINFO;
	sig_act_msgchk.__sigaction_u.__sa_sigaction = handler;
	while (sigemptyset(&sig_act_msgchk.sa_mask) != 0)
		;
	while (sigaction(SIGUSR1, &sig_act_msgchk, NULL))
		;
	while (sigaction(SIGUSR2, &sig_act_msgchk, NULL))
		;
	send_message(msg, ft_strlen(msg), pid);
}
