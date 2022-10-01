/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:13:38 by junsyun           #+#    #+#             */
/*   Updated: 2022/10/01 23:03:50 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk.h"


pid_t	get_pid_integer(char *str)
{
	pid_t	pid;

	pid = 0;
	while (*str)
		pid = pid * 10 + *str++ - '0';
	return (pid);
}

void	err_exit(char *str)
{
	int	len;

	len = ft_strlen(str);
	write(2, str, len);
	write(2, "\n", 1);
	exit(1);
}

void	success_exit(char *str)
{
	ft_printf("%s\n", str);
	exit(0);
}

void	exec_kill(pid_t pid, int sig)
{
	if (kill(pid, sig) == -1)
		err_exit("[ERROR] kill() error");
}

