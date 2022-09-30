/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:13:38 by junsyun           #+#    #+#             */
/*   Updated: 2022/09/30 12:26:51 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

static size_t	ft_strlen(char *str)
{
	size_t	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
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
