/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 11:34:27 by junsyun           #+#    #+#             */
/*   Updated: 2022/10/02 00:22:36 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handler(int sig, siginfo_t *info, void *ucontext)
{
	static int				i;
	static unsigned char	c;
	static int				client_pid;
	int						bit;
	int						kill_status;

	(void)ucontext;
	if (sig == SIGUSR1)
		bit = 0;
	else
		bit = 1;
	c = c | (bit << i);
	if (i == 8 - 1)
	{
		write(1, &c, 1);
		c = 0;
		kill(client_pid, SIGUSR2);
	}
	i = (i + 1) % 8;
	if (info->si_pid != 0)
		client_pid = info->si_pid;
	kill_status = -1;
	while (kill_status != 0)
		kill_status = kill(client_pid, SIGUSR1);
}

static size_t	get_pid_length(pid_t pid)
{
	size_t	length;

	length = 1;
	if (pid < 0)
	{
		pid = -pid;
		length++;
	}
	while (pid > 9)
	{
		pid /= 10;
		length++;
	}
	return (length);
}

static char	*get_pid_string(pid_t pid)
{
	char	*str;
	size_t	length;

	length = get_pid_length(pid);
	str = malloc(sizeof(char) * (length + 1));
	if (str == NULL)
		return (NULL);
	str[length] = '\0';
	while (length)
	{
		str[length - 1] = pid % 10 + '0';
		pid /= 10;
		length--;
	}
	return (str);
}

static void	print_pid(pid_t pid)
{
	char	*pid_str;
	pid_str = get_pid_string(pid);
	ft_printf("This Server\'s PID : %s\n", pid_str);
	free(pid_str);
}

int	main(void)
{
	struct sigaction	sig_act;

	sig_act.sa_flags = SA_SIGINFO;
	sig_act.__sigaction_u.__sa_sigaction = handler;
	sigemptyset(&sig_act.sa_mask);
	sigaction(SIGUSR1, &sig_act, NULL);
	sigaction(SIGUSR2, &sig_act, NULL);
	print_pid(getpid());
	write(1, "\n", 1);
	while (1)
		pause();
}
