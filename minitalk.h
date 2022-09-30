/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 03:23:39 by junsyun           #+#    #+#             */
/*   Updated: 2022/09/30 12:27:19 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <stdarg.h>

int				ft_putchar(char c);
int				ft_putnbr_base(unsigned long n);
int				ft_putnbr(int n);
int				ft_putstr(char *s);
int				ft_atoi(const char *str);
int				ft_printf(const char *format, ...);

static size_t	ft_strlen(char *str);
#endif
