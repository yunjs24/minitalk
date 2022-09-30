/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 08:36:36 by junsyun           #+#    #+#             */
/*   Updated: 2022/08/12 12:48:17 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putnbr_base(unsigned int n, char *base)
{
	int				base_size;
	unsigned int	tmp[8];
	int				i;
	int				rt_val;

	i = 0;
	base_size = ft_strlen(base);
	if (n == 0)
		return (write(1, "0", 1));
	while (n != 0)
	{
		tmp[i] = n % base_size;
		n = n / base_size;
		i++;
	}
	rt_val = i;
	i = rt_val;
	while (--i >= 0)
		write(1, &base[tmp[i]], 1);
	return (rt_val);
}
