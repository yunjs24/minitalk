/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 03:23:39 by junsyun           #+#    #+#             */
/*   Updated: 2022/10/01 22:30:03 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <stdarg.h>
# include "ft_printf/ft_printf.h"

int	ft_atoi(const char *str);
int	ft_printf(const char *format, ...);

pid_t	get_pid_integer(char *str);
void	err_exit(char *str);
void	success_exit(char *str);
void	exec_kill(pid_t pid, int sig);
// size_t	ft_strlen(char *str);

#endif
