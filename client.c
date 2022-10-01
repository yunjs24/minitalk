/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 11:11:44 by junsyun           #+#    #+#             */
/*   Updated: 2022/10/01 22:31:13 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_rcv_status;

static void	handler(int sig, siginfo_t *info, void *ucontext)
{
	(void)sig;
	(void)info;
	(void)ucontext;
	g_rcv_status = 1;
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
			if (bit % 2 == 0)
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
	struct sigaction	sig_act;
	pid_t				pid;
	char				*msg;

	if (argc != 3)
		return (1);
	pid = (pid_t)get_pid_integer(argv[1]);
	if (pid < 100 || pid > 9999998)
		err_exit("Error : Bad PID !");
	msg = argv[2];
	sig_act.sa_flags = SA_SIGINFO;
	sig_act.__sigaction_u.__sa_sigaction = handler;
	while (sigemptyset(&sig_act.sa_mask) != 0)
		usleep(50);
	while (sigaction(SIGUSR1, &sig_act, NULL))
		usleep(50);
	send_message(msg, ft_strlen(msg), pid);
}
