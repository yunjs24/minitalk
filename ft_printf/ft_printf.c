/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 23:40:08 by junsyun           #+#    #+#             */
/*   Updated: 2022/07/20 00:10:29 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_type(const char *str, va_list ap, int ret)
{
	if (*str == 'c')
		ret += ft_putchar(va_arg(ap, int));
	else if (*str == 's')
		ret += ft_putstr(va_arg(ap, char *));
	else if (*str == 'p')
		ret += ft_putnbr_p(va_arg(ap, size_t), "0123456789abcdef");
	else if (*str == 'd' || *str == 'i')
		ret += ft_putnbr_di(va_arg(ap, int));
	else if (*str == 'u')
		ret += ft_putnbr_base(va_arg(ap, unsigned int), "0123456789");
	else if (*str == 'x')
		ret += ft_putnbr_base(va_arg(ap, unsigned int), "0123456789abcdef");
	else if (*str == 'X')
		ret += ft_putnbr_base(va_arg(ap, unsigned int), "0123456789ABCDEF");
	else if (*str == '%')
		ret += write(1, "%", 1);
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		ret;

	ret = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ret = handle_type(format, ap, ret);
			format++;
			continue ;
		}
		ret += write(1, format++, 1);
	}
	va_end(ap);
	return (ret);
}
