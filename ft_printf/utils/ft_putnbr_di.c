/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_di.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 08:36:18 by junsyun           #+#    #+#             */
/*   Updated: 2022/07/19 09:09:34 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putnbr_di(int n)
{
	unsigned int	x;

	x = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		x = -n;
	}
	else
		x = n;
	if (x > 9)
	{
		ft_putnbr_di(x / 10);
		ft_putnbr_di(x % 10);
	}
	else
	{
		x += '0';
		write(1, &x, 1);
	}
	return (ft_intlen(n));
}
