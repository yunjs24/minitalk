/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 08:36:25 by junsyun           #+#    #+#             */
/*   Updated: 2022/08/12 12:14:41 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putnbr_p(size_t n, char *base)
{
	int		base_size;
	size_t	tmp[16];
	int		i;
	int		rt_val;

	write(1, "0x", 2);
	i = 0;
	base_size = ft_strlen(base);
	if (n == 0)
		return (write(1, "0", 1) + 2);
	while (n != 0)
	{
		tmp[i] = n % base_size;
		n = n / base_size;
		i++;
	}
	rt_val = 2 + i;
	while (--i >= 0)
		write(1, &base[tmp[i]], 1);
	return (rt_val);
}
